/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:03:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/25 15:30:54 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	max_to_top(t_pw *s)
{
	int	max;

	//print_stacks(s);
	max = find_max(s->b);
	while (s->b->size > 0)
	{
		if (top(s->b) == max)
			pa(s->a, s->b);
		max = find_max(s->b);
		if (closer_to_top(s->b, max))
			rb(s->b);
		else
			rrb(s->b);
	}
	//print_stacks(s);
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

/*void	split_B_bigger(t_pw *s, int average)
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
}*/

void	split_B_bigger(t_pw *s, int average)
{
	if (s->b->size < average / 2)
		return ;
	if (top(s->b) == 0 || top(s->b) == bot(s->a) + 1)
		push_rotate(s);
	else if (top(s->b) >= average)
		pa(s->a, s->b);
	else if (s->b->size < 13)
		max_to_top(s);
	else
		rb(s->b);
}

void	solve_B(t_pw *s)
{
	int	max;

	if (s->b->size == 0)
		return ;
	max = find_max(s->b);
	split_B_bigger(s, find_average(s->b));
	while (top(s->a) == bot(s->a) + 1 && top(s->a) != 0)
		ra(s->a);
	//print_stacks(s);
	solve_B(s);
	//print_stacks(s);
	//push_next_half(s, max);
	max = max;
}

void	solve_big(t_pw *s)
{
	int	average;

	if (check_sort(s->a))
		return ;
	average = find_average(s->a);
	split_A_smaller(s, average);
	solve_B(s);
	//push_next_half(s, find_max(s->a));
}
