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
	if (ft_strncmp(key, SA, 4) == EQUAL && *a)
		operation_swap("", *a, NULL);
	else if (ft_strncmp(key, SB, 4) == EQUAL && *b)
		operation_swap("", *b, NULL);
	else if (ft_strncmp(key, SS, 4) == EQUAL && *b && *a)
		operation_swap("", *a, *b);
	else if (ft_strncmp(key, PA, 4) == EQUAL && *b)
		operation_push("", b, a);
	else if (ft_strncmp(key, PB, 4) == EQUAL && *a)
		operation_push("", a, b);
	else if (ft_strncmp(key, RA, 4) == EQUAL && *a)
		operation_rotate("", a, NULL);
	else if (ft_strncmp(key, RB, 4) == EQUAL && *b)
		operation_rotate("", b, NULL);
	else if (ft_strncmp(key, RR, 4) == EQUAL && *a && *b)
		operation_rotate("", a, b);
	else
		return (ERR_BIT);
	return (SUCCESS);
}

static int	key4_action(const char *key, t_list **a, t_list **b)
{
	if (ft_strncmp(key, RRA, 5) == EQUAL && *a)
		operation_rrotate("", a, NULL);
	else if (ft_strncmp(key, RRB, 5) == EQUAL && *b)
		operation_rrotate("", b, NULL);
	else if (ft_strncmp(key, RRR, 5) == EQUAL && *a && *b)
		operation_rrotate("", a, b);
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
	char	key[6];
	int		readed;
	int		is_operation;

	while (SUCCESS)
	{
		readed = read(0, key, 5);
		if ((readed == 1 && key[0] == '\n') || !readed)
			break ;
		else if (readed < 2 || readed > 4)
			return (ERR_BIT);
		key[readed] = '\0';
		if (readed == 3)
			is_operation = key3_action((const char *)key, a, b);
		else
			is_operation = key4_action((const char *)key, a, b);
		if (is_operation == ERR_BIT)
			return (ERR_BIT);
	}
	if (is_sorted(*a))
		return (SUCCESS);
	else
		return (FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		proccess_bit;

	if (argc == 1)
		return (EXIT_FAILURE);
	a = NULL;
	b = NULL;
	proccess_bit = ERR_BIT;
	if (is_valid_args(argc - 1, argv + 1))
	{
		a = return_list(argc - 1, argv + 1, content_utilization);
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
