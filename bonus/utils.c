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
	if (index == 1)
		ft_putstr_fd("OK\n", 1);
	else if (index == 0)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("Error\n", 2);
}

int	content_cmp(void *first, void *second)
{
	int	a;
	int	b;

	a = (int)((t_data *)first)->index;
	b = (int)((t_data *)second)->index;
	return (a - b);
}
