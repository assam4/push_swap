/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:32:36 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/18 21:44:20 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

static long	ft_strtol(char **str)
{
	long	result;
	int		sign;

	sign = 1;
	result = START;
	while (**str && ft_isspace(**str))
		++(*str);
	if (**str == MINUS)
		sign = -1;
	if (**str == PLUS || **str == MINUS)
		++(*str);
	while (**str && ft_isdigit(**str))
	{
		result = result * 10 + (**str - '0');
		++(*str);
	}
	return (sign * result);
}

static size_t	get_index(t_list *a, int num)
{
	size_t	index;
	t_data	*data;

	if (!a)
		return (FAILURE);
	index = START;
	while (a)
	{
		data = (t_data *)a->content;
		if (num < data->number)
		{
			if (index > data->index)
				index = data->index;
			++(data->index);
		}
		else if (data->index >= index)
			index = data->index + 1;
		a = a->next;
	}
	return (index);
}

static t_list	*create_node(long number, size_t index)
{
	void	*content;

	content = malloc(sizeof(t_data));
	if (!content)
		return (NULL);
	((t_data *)content)->number = (int)number;
	((t_data *)content)->index = index;
	return (ft_lstnew(content));
}

static int	add_to_list(char *arg, t_list **stack)
{
	long	number;
	size_t	index;
	t_list	*next;

	while (arg && *arg)
	{
		number = ft_strtol(&arg);
		if (!is_unique(*stack, number)
			|| (*arg && !is_within_int(number, arg)))
			return (FAILURE);
		index = get_index(*stack, number);
		next = create_node(number, index);
		if (!next)
			return (FAILURE);
		ft_lstadd_back(stack, next);
	}
	return (SUCCESS);
}

t_list	*return_list(int argc, char **argv, void (*deallocate)(void *))
{
	int		i;
	int		is_allocated;
	t_list	*list;

	i = LOOP_START;
	list = NULL;
	while (++i < argc)
	{
		is_allocated = add_to_list(argv[i], &list);
		if (!is_allocated)
		{
			ft_lstclear(&list, deallocate);
			return (NULL);
		}
	}
	return (list);
}
