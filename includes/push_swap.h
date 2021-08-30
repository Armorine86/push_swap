/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:23:46 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/27 13:49:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
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

/* SOLVER */

void			solve_big(t_pw *s);
void			solve_small(t_pw *s);
void			quicksort(t_stack *s);
void			dual_quicksort(t_stack *s);
void			push_next_half(t_pw *s, int max);
void			sort_rest(t_pw *s);
void			solve_b(t_pw *s);
void			max_to_top(t_pw *s);

/* UTILITIES */

int				find_max(t_stack *s);
int				find_min(t_stack *s);
int				bot(t_stack *s);
int				top(t_stack *s);
void			free_tab(char **tab);
void			error_exit(void);
void			free_all_exit(t_pw *s);
bool			check_sort(t_stack *s);
bool			check_smaller_than_average(t_stack *a, int average);
bool			check_bigger_than_average(t_stack *b, int average);

/* SORT_UTILITIES */

void			push_rotate(t_pw *s);
void			rank_stacks(t_stack *a, t_stack *c);
bool			closer_to_top(t_stack *s, int num);
int				find_average(t_stack *s);
int				find_index(t_stack *s, int num);

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