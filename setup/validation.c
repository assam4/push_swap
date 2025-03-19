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
			if (!i || string[i - 1] == SPACE)
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

int	is_within_int(long number, char *arg)
{
	char	*str_nb;

	if (INT_MIN > number || number > INT_MAX)
		return (FAILURE);
	str_nb = ft_itoa((int)number);
	return (ft_strncmp(str_nb, arg - ft_strlen(str_nb),
			ft_strlen(str_nb)) == FAILURE);
}

int	is_unique(t_list *lst, long num)
{
	t_data	*content;

	if (lst)
	{
		while (lst)
		{
			content = (t_data *)lst->content;
			if (content->number == (int)num)
				return (FAILURE);
			lst = lst->next;
		}
	}
	return (SUCCESS);
}
