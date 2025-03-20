/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:21:43 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 19:54:58 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"

# define EX_SMALL 3
# define SORT_DIVIDER 12

// small_data_sort
void	small_data_sort(t_list **a, t_list **b);
void	go_between(t_list **a, t_list *b);
// big data sort
void	butterfly_sort(t_list **a, t_list **b);

#endif
