/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:32:29 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 18:18:38 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_sqrt(size_t nb)
{
	size_t	root;

	root = SUCCESS;
	if (nb <= root)
		return (root);
	while ((root * root) < nb)
	{
		++root;
		if (root * root == nb)
			return (root);
	}
	return (root);
}

static size_t	ft_log(size_t n, size_t nb)
{
	size_t	result;
	size_t	exponent;

	result = SUCCESS;
	exponent = START;
	while (result < nb)
	{
		++exponent;
		result *= n;
	}
	return (exponent);
}

static size_t	go_to_max(t_list *iter, size_t max)
{
	size_t	steps;

	steps = START;
	while (index_cmp(iter->content, max) != EQUAL)
	{
		iter = iter->next;
		++steps;
	}
	return (steps <= (max + ONE) / TWO);
}

static void	reverse_push(t_list **a, t_list **b, size_t max_index)
{
	size_t	path;

	while (*b)
	{
		path = go_to_max(*b, max_index);
		if (path)
			while (index_cmp((*b)->content, max_index) != EQUAL)
				operation_rotate(RB, b, NULL);
		else
			while (index_cmp((*b)->content, max_index) != EQUAL)
				operation_rrotate(RRB, b, NULL);
		operation_push(PA, b, a);
		--max_index;
	}
}

void	butterfly_sort(t_list **a, t_list **b)
{
	size_t	coefficient;
	size_t	counter;
	size_t	nums_count;

	nums_count = ft_lstsize(*a);
	coefficient = ft_sqrt(nums_count) + ft_log(TWO, nums_count) - ONE;
	counter = START;
	while (*a)
	{
		if (index_cmp((*a)->content, counter + coefficient) <= EQUAL)
		{
			operation_push(PB, a, b);
			if (index_cmp((*b)->content, counter) <= EQUAL)
				operation_rotate(RB, b, NULL);
			++counter;
		}
		else
			operation_rotate(RA, a, NULL);
	}
	reverse_push(a, b, nums_count - ONE);
}
