/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:23:46 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/16 08:56:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*num;
	int	size;
}		t_stack;

typedef struct s_pw
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
}		t_pw;

static void		argv_to_stack(t_stack *a, t_stack *c, char **argv, int size);
int				validate_args(char **argv, int size);
int				build_stacks(t_pw *stack, char **argv, int size);
void			free_tab(char **tab);
void			error_exit(void);
void			free_stacks(t_stack *s);
void			free_all_exit(t_pw *s);



#endif