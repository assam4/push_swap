/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:23:12 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 19:56:34 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "setup.h"

# define EQUAL 0
# define MAX "max"
# define MIN "min"

void	operation_swap(char *step, t_list *basic, t_list *additional);
void	operation_push(char *step, t_list **basic, t_list **additional);
void	operation_rotate(char *step, t_list **basic, t_list **additional);
void	operation_rrotate(char *step, t_list **basic, t_list **additional);
// sorting utils
void	content_utilization(void *content);
int		index_cmp(void *first, size_t index);
size_t	find_extreme(t_list *a, char *s);
void	go_to_min(t_list **a, size_t min);
size_t	path_between(t_list *a, size_t index, size_t min);

#endif 
