/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:38:46 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 20:36:59 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	key3_action(const char *key, t_list **a, t_list **b)
{
	if (ft_strncmp(key, SA, KEY_1) == EQUAL && *a)
		operation_swap(NO_INPUT, *a, NULL);
	else if (ft_strncmp(key, SB, KEY_1) == EQUAL && *b)
		operation_swap(NO_INPUT, *b, NULL);
	else if (ft_strncmp(key, SS, KEY_1) == EQUAL && *b && *a)
		operation_swap(NO_INPUT, *a, *b);
	else if (ft_strncmp(key, PA, KEY_1) == EQUAL && *b)
		operation_push(NO_INPUT, b, a);
	else if (ft_strncmp(key, PB, KEY_1) == EQUAL && *a)
		operation_push(NO_INPUT, a, b);
	else if (ft_strncmp(key, RA, KEY_1) == EQUAL && *a)
		operation_rotate(NO_INPUT, a, NULL);
	else if (ft_strncmp(key, RB, KEY_1) == EQUAL && *b)
		operation_rotate(NO_INPUT, b, NULL);
	else if (ft_strncmp(key, RR, KEY_1) == EQUAL && *a && *b)
		operation_rotate(NO_INPUT, a, b);
	else
		return (ERR_BIT);
	return (SUCCESS);
}

static int	key4_action(const char *key, t_list **a, t_list **b)
{
	if (ft_strncmp(key, RRA, KEY_2) == EQUAL && *a)
		operation_rrotate(NO_INPUT, a, NULL);
	else if (ft_strncmp(key, RRB, KEY_2) == EQUAL && *b)
		operation_rrotate(NO_INPUT, b, NULL);
	else if (ft_strncmp(key, RRR, KEY_2) == EQUAL && *a && *b)
		operation_rrotate(NO_INPUT, a, b);
	else
		return (ERR_BIT);
	return (SUCCESS);
}

static int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (content_cmp(a->next->content, a->content) > EQUAL)
			a = a->next;
		else
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	checker(t_list **a, t_list **b)
{
	char	*operation;
	int		is_operation;

	while (SUCCESS)
	{
		operation =  get_next_line(STDIN_FILENO);
		if (!operation || *operation == '\n')
			break ;
		if (ft_strlen(operation) == KEY_1)
			is_operation = key3_action((const char *)operation, a, b);
		else if (ft_strlen(operation) == KEY_2)
			is_operation = key4_action((const char *)operation, a, b);
		else
			return (free(operation), ERR_BIT);
		free(operation);
		if (!is_operation)
			return (ERR_BIT);
	}
	if (is_sorted(*a) && !(*b))
		return (SUCCESS);
	else
		return (FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		proccess_bit;

	if (argc == ONE)
		return (EXIT_FAILURE);
	a = NULL;
	b = NULL;
	proccess_bit = ERR_BIT;
	if (is_valid_args(argc - ONE, argv + ONE))
	{
		a = return_list(argc - ONE, argv + ONE, content_utilization);
		if (a)
		{
			proccess_bit = checker(&a, &b);
			if (b)
				ft_lstclear(&b, content_utilization);
			if (a)
				ft_lstclear(&a, content_utilization);
		}
		print_message(proccess_bit);
	}
	return (EXIT_SUCCESS);
}
