/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:33:07 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 20:03:44 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	content_utilization(void *content)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
}

int	index_cmp(void *first, size_t index)
{
	int	a;
	int	b;

	a = (int)((t_data *)first)->index;
	b = (int)index;
	return (a - b);
}

size_t	find_extreme(t_list	*list, char *s)
{
	size_t	index;

	index = ((t_data *)(list->content))->index;
	list = list->next;
	while (list)
	{
		if ((ft_strncmp(s, MAX, ft_strlen(MAX))
				&& index_cmp(list->content, index) < EQUAL)
			|| (ft_strncmp(s, MIN, ft_strlen(MIN))
				&& index_cmp(list->content, index) > EQUAL))
			index = ((t_data *)(list->content))->index;
		list = list->next;
	}
	return (index);
}

size_t	path_between(t_list *a, size_t index, size_t min)
{
	size_t	steps;
	size_t	half;

	steps = START;
	half = ft_lstsize(a) / 2;
	while (a)
	{
		if (!min && index_cmp(a->content, index) > EQUAL
			&& index_cmp(ft_lstlast(a)->content, index) < EQUAL)
			break ;
		if (min && index_cmp(a->content, index) == EQUAL)
			break ;
		++steps;
		a = a->next;
	}
	return (steps <= half);
}

void	go_to_min(t_list **a, size_t min)
{
	size_t	path;

	path = path_between(*a, min, ONE);
	while (index_cmp((*a)->content, min) != EQUAL)
	{
		if (path)
		{
			operation_rotate(RA, a, NULL);
		}
		else
			operation_rrotate(RRA, a, NULL);
	}
}
