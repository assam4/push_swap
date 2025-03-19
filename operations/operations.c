/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:32:44 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/19 19:25:28 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	operation_swap(char *step, t_list *basic, t_list *additional)
{
	void	*temp;

	temp = NULL;
	if (basic && basic->next)
	{
		temp = basic->content;
		basic->content = basic->next->content;
		basic->next->content = temp;
	}
	if (additional && additional->next)
	{
		temp = additional->content;
		additional->content = additional->next->content;
		additional->next->content = temp;
	}
	ft_putstr_fd(step, 1);
}

void	operation_push(char *step, t_list **basic, t_list **additional)
{
	t_list	*temp;

	if (ft_lstsize(*basic) > START)
	{
		temp = *basic;
		*basic = (*basic)->next;
		temp->next = NULL;
		ft_lstadd_front(additional, temp);
		ft_putstr_fd(step, 1);
	}
}

void	operation_rotate(char *step, t_list **basic, t_list **additional)
{
	t_list	*temp;

	if (ft_lstsize(*basic) >= 2)
	{
		temp = *basic;
		*basic = (*basic)->next;
		temp->next = NULL;
		ft_lstadd_back(basic, temp);
	}
	if (additional && ft_lstsize(*additional))
	{
		temp = *additional;
		*additional = (*additional)->next;
		temp->next = NULL;
		ft_lstadd_back(additional, temp);
	}
	ft_putstr_fd(step, 1);
}

static t_list	*throw_last(t_list **list)
{
	t_list	*iter;
	t_list	*last;

	if (!*list)
		return (NULL);
	iter = (*list);
	while (iter->next && iter->next->next)
		iter = iter->next;
	last = iter->next;
	iter->next = NULL;
	return (last);
}

void	operation_rrotate(char *step, t_list **basic, t_list **additional)
{
	t_list	*temp;

	if (ft_lstsize(*basic) >= 2)
	{
		temp = throw_last(basic);
		ft_lstadd_front(basic, temp);
	}
	if (additional && ft_lstsize(*additional) >= 2)
	{
		temp = throw_last(additional);
		ft_lstadd_front(additional, temp);
	}
	ft_putstr_fd(step, 1);
}
