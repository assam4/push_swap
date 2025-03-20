/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:00:31 by saslanya          #+#    #+#             */
/*   Updated: 2025/03/18 21:45:44 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "libft.h"
# include <limits.h>

# define SUCCESS 1
# define FAILURE 0
# define LOOP_START -1
# define START 0
# define SPACES "\n \t \r \v \f"
# define SPACE ' '
# define PLUS '+'
# define MINUS '-'

typedef struct s_data
{
	int		number;
	size_t	index;
}		t_data;

int		ft_isspace(int letter);
int		is_valid_args(int count, char **argv);
int		is_within_int(int number, char **arg);
int		is_unique(t_list *lst, long num);
t_list	*return_list(int argc, char **argv, void (*deallocate)(void *));

#endif
