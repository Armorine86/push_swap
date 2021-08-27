/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:03:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/27 13:49:00 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	max_to_top(t_pw *s)
{
	int	max;

	if (s->b->size == 0)
		return ;
	max = find_max(s->b);
	if (top(s->b) == max)
	{
		pa(s->a, s->b);
		return ;
	}
	if (closer_to_top(s->b, max))
		rb(s->b);
	else
		rrb(s->b);
	max_to_top(s);
}

void	split_a_smaller(t_pw *s, int average)
{
	if (!check_smaller_than_average(s->a, average))
		return ;
	if (top(s->a) < average)
		pb(s->a, s->b);
	else
		ra(s->a);
	split_a_smaller(s, average);
}

void	split_b_bigger(t_pw *s, int average, int limit)
{
	if (limit == 0)
		return ;
	if (top(s->b) == 0 || top(s->b) == bot(s->a) + 1)
		push_rotate(s);
	else if (s->b->size < 13)
		max_to_top(s);
	else if (top(s->b) >= average)
		pa(s->a, s->b);
	else
		rb(s->b);
	split_b_bigger(s, average, limit - 1);
}

void	solve_b(t_pw *s)
{
	int	max;
	int	limit;

	if (s->b->size == 0)
		return ;
	limit = s->b->size;
	max = find_max(s->b);
	split_b_bigger(s, find_average(s->b), limit);
	while (top(s->a) == bot(s->a) + 1 && top(s->a) != 0)
		ra(s->a);
	solve_b(s);
	push_next_half(s, limit);
	push_next_half(s, max);
}

void	solve_big(t_pw *s)
{
	int	average;

	average = find_average(s->a);
	split_a_smaller(s, average);
	solve_b(s);
	push_next_half(s, find_max(s->a));
}
