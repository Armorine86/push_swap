/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:23:46 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/18 11:38:09 by mmondell         ###   ########.fr       */
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

int				validate_args(char **argv, int size);
int				build_stacks(t_pw *stack, int size);
void			execute_sorting(t_stack *a, t_stack *b, t_stack *c);
void			free_tab(char **tab);
void			error_exit(void);
void			free_stacks(t_stack *s);
void			free_all_exit(t_pw *s);

/* OPERATIONS */
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

#endif