/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:03:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/24 20:52:31 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	max_to_top(t_pw *s)
{
	int	max;

	max = find_max(s->b);
	if (top(s->b) == max)
	{
		pa(s->a, s->b);
		return ;
	}
	while (top(s->b) != max)
	{
		if (closer_to_top(s->b, max))
			rb(s->b);
		else
			rrb(s->b);
	}
}

void	split_B_bigger(t_pw *s, int average)
{
	if (s->b->size == 0)
		return ;
	while (check_bigger_than_average(s->b, average))
	{
		if (top(s->b) == 0 || top(s->b) == bot(s->a) + 1)
			push_rotate(s);
		else if (top(s->b) >= average)
			pa(s->a, s->b);
		else
			rb(s->b);
	}
	while (s->b->size >= 13)
	{
		if (closer_to_top(s->b, bot(s->a) + 1))
			rb(s->b);
		else
			rrb(s->b);
		if (top(s->b) == bot(s->a) + 1)
			push_rotate(s);
	}
	if (s->b->size < 13)
		max_to_top(s);
}

void	split_A_smaller(t_pw *s, int average)
{
	if (!check_smaller_than_average(s->a, average))
		return ;
	if (top(s->a) < average)
		pb(s->a, s->b);
	else
		ra(s->a);
	//print_stacks(s);
	split_A_smaller(s, average);
}

void	solve_B(t_pw *s, int average)
{
	//int	max;

	//max = find_max(s->b);
	if (s->b->size == 0)
		return ;
	split_B_bigger(s, average);
	solve_B(s, average);
	//push_sort_to_top(s->a, max);
}

void	solve_big(t_pw *s)
{
	if (check_sort(s->a))
		return ;
	//print_stacks(s);
	split_A_smaller(s, find_average(s->a));
	//print_stacks(s);
	solve_B(s, find_average(s->b));
	//print_stacks(s);
}
