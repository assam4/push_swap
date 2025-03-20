/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:44:36 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 19:53:50 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_message(int index)
{
	if (index == SUCCESS)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else if (index == FAILURE)
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	else if (index == ERR_BIT)
		ft_putstr_fd("Error\n", STDERR_FILENO);
}

int	content_cmp(void *first, void *second)
{
	int	a;
	int	b;

	a = (int)((t_data *)first)->index;
	b = (int)((t_data *)second)->index;
	return (a - b);
}
