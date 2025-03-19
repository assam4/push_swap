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
	if (ft_strncmp(key, "sa\n", 4) == 0 && *a)
		operation_swap("", *a, NULL);
	else if (ft_strncmp(key, "sb\n", 4) == 0 && *b)
		operation_swap("", *b, NULL);
	else if (ft_strncmp(key, "ss\n", 4) == 0 && *b && *a)
		operation_swap("", *a, *b);
	else if (ft_strncmp(key, "pa\n", 4) == 0 && *b)
		operation_push("", b, a);
	else if (ft_strncmp(key, "pb\n", 4) == 0 && *a)
		operation_push("", a, b);
	else if (ft_strncmp(key, "ra\n", 4) == 0 && *a)
		operation_rotate("", a, NULL);
	else if (ft_strncmp(key, "rb\n", 4) == 0 && *b)
		operation_rotate("", b, NULL);
	else if (ft_strncmp(key, "rr\n", 4) == 0 && *a && *b)
		operation_rotate("", a, b);
	else
		return (-1);
	return (SUCCESS);
}

static int	key4_action(const char *key, t_list **a, t_list **b)
{
	if (ft_strncmp(key, "rra\n", 5) == 0 && *a)
		operation_rrotate("", a, NULL);
	else if (ft_strncmp(key, "rrb\n", 5) == 0 && *b)
		operation_rrotate("", b, NULL);
	else if (ft_strncmp(key, "rrr\n", 5) == 0 && *a && *b)
		operation_rrotate("", a, b);
	else
		return (-1);
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
	char	key[5];
	int		readed;
	int		is_operation;

	while (1)
	{
		readed = read(0, key, 5);
		if ((readed == 1 && key[0] == '\n') || !readed)
			break ;
		else if (readed < 2)
			return (-1);
		key[readed] = '\0';
		if (readed == 3)
			is_operation = key3_action((const char *)key, a, b);
		else
			is_operation = key4_action((const char *)key, a, b);
		if (is_operation == 0)
			return (-1);
	}
	if (is_sorted(*a))
		return (1);
	else
		return (0);
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
	proccess_bit = -1;
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
