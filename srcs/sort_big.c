/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:03:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/23 20:40:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	max_to_top(t_stack *a, t_stack *b)
{
	int	max;

	max = find_max(b);
	if (top(b) == max)
	{
		pa(a, b);
		return ;
	}
	while (top(b) != max)
	{
		if (closer_to_top(b, max))
			rb(b);
		else
			rrb(b);
	}
}

void	split_B_bigger(t_stack *a, t_stack *b, int average)
{
	if (b->size <= average)
		return ;
	if (top(b) == 0 || top(b) == bot(a) + 1)
	{
		pa(a, b);
		ra(a);
	}
	else if (b->size < 13)
		max_to_top(a, b);
	else if (top(b) >= average)
		pa(a, b);
	else
		rb(b);
	print_stack(a, b);
	split_B_bigger(a, b, average);
}

void	split_A_smaller(t_stack *a, t_stack *b,	int average)
{
	if (a->size <= average)
		return ;
	if (top(a) <= average)
		pb(a, b);
	ra(a);
	split_A_smaller(a, b, average);
}

void	solve_B(t_stack *a, t_stack *b)
{	
	if (b->size == 0)
		return ;
	split_B_bigger(a, b, find_average(b));
	solve_B(a, b);
	
}

void	solve_big(t_stack *a, t_stack *b, t_stack *c)
{
	if (check_sort(a))
		return ;
	split_A_smaller(a, b, find_average(a));
	print_stack(a, b);
	solve_B(a, b);
	print_stack(a, b);
	c->size = c->size;
}
