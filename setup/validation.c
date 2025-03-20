/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:38:15 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/18 21:45:05 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

int	ft_isspace(int letter)
{
	char	*pointer;

	pointer = ft_strchr(SPACES, letter);
	if (pointer)
		return (SUCCESS);
	else
		return (FAILURE);
}

static int	is_valid_string(char *string)
{
	int	i;

	i = START;
	if (!ft_strlen(string))
		return (FAILURE);
	while (string && string[i])
	{
		if (ft_isspace(string[i]))
			++i;
		else if (string[i] == PLUS
			|| string[i] == MINUS)
		{
			if (!i || string[i - ONE] == SPACE)
				++i;
			else
				return (FAILURE);
		}
		if (!ft_isdigit(string[i++]))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	is_valid_args(int count, char **argv)
{
	int	index;
	int	str_bit;

	index = LOOP_START;
	while (++index < count)
		str_bit = is_valid_string(argv[index]);
	return (str_bit);
}

int	is_within_int(int number, char **arg)
{
	char	*num_str;
	int		i;

	num_str = ft_itoa(number);
	i = START;
	if (num_str)
	{
		if ((*arg)[i] == MINUS && num_str[i] == MINUS)
			++i;
		else if ((*arg)[i] == PLUS)
			++(*arg);
		while ((*arg)[i] == '0' && num_str[i] != '0')
			++(*arg);
		while (num_str[i] && (*arg)[i])
		{
			if ((*arg)[i] != num_str[i])
				return (free(num_str), FAILURE);
			++i;
		}
		(*arg) += i;
		return (free(num_str), SUCCESS);
	}
	return (FAILURE);
}

int	is_unique(t_list *lst, long num)
{
	t_data	*content;

	while (lst)
	{
		content = (t_data *)lst->content;
		if (content->number == (int)num)
			return (FAILURE);
		lst = lst->next;
	}
	return (SUCCESS);
}
