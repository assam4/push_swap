/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:33:00 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 20:04:39 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	content_cmp(void *first, void *second)
{
	int	a;
	int	b;

	a = (int)((t_data *)first)->index;
	b = (int)((t_data *)second)->index;
	return (a - b);
}

void	go_between(t_list **a, t_list *b)
{
	size_t	index;

	index = ((t_data *)(b->content))->index;
	while (SUCCESS)
	{
		if (index_cmp((*a)->content, index) > EQUAL
			&& index_cmp(ft_lstlast(*a)->content, index) < EQUAL)
			break ;
		if (path_between(*a, index, START))
			operation_rotate(RA, a, NULL);
		else
			operation_rrotate(RRA, a, NULL);
	}
}

static void	three_number_sort(t_list **a)
{
	int	is_true;

	is_true = SUCCESS;
	while (is_true && ft_lstsize(*a) > ONE)
	{
		is_true = FAILURE;
		if (content_cmp((*a)->content, ft_lstlast(*a)->content) > EQUAL)
		{
			is_true = SUCCESS;
			if ((ft_lstsize(*a) == EX_SMALL)
				&& content_cmp((*a)->content, (*a)->next->content) < EQUAL)
				operation_rrotate(RRA, a, NULL);
			else
				operation_rotate(RA, a, NULL);
		}
		if (ft_lstsize(*a) == EX_SMALL
			&& (content_cmp((*a)->content, (*a)->next->content) > EQUAL
				|| content_cmp((*a)->next->next->content
					, (*a)->next->content) < EQUAL))
		{
			is_true = SUCCESS;
			operation_swap(SA, *a, NULL);
		}
	}
}

void	small_data_sort(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > EX_SMALL)
		operation_push(PB, a, b);
	three_number_sort (a);
	while (*b)
	{
		if (index_cmp((*b)->content, find_extreme(*a, MAX)) > EQUAL
			|| index_cmp((*b)->content, find_extreme(*a, MIN)) < EQUAL)
			go_to_min(a, find_extreme(*a, MIN));
		else
		{
			go_between(a, *b);
		}
		operation_push(PA, b, a);
	}
	if (ft_lstsize(*a) > EX_SMALL)
		go_to_min(a, START);
}
