/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:32:52 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 19:35:14 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc == ONE)
		return (EXIT_FAILURE);
	a = NULL;
	b = NULL;
	if (is_valid_args(argc - ONE, argv + ONE))
	{
		a = return_list(argc - ONE, argv + ONE, content_utilization);
		if (a && a->content)
		{
			if (ft_lstsize(a) <= SORT_DIVIDER)
				small_data_sort(&a, &b);
			else
				butterfly_sort(&a, &b);
			ft_lstclear(&a, content_utilization);
			return (EXIT_SUCCESS);
		}
	}
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}
