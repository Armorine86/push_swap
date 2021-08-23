/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:28:23 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/23 13:11:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_if_closer_to_top(t_stack *a, t_stack *b, int i)
{
	while (a->num[a->size - 1] != i)
	{
		if (closer_to_top(a, i))
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}

int	find_max(t_stack *s)
{
	int	max;
	int	i;

	i = 0;
	max = s->num[0];
	while (i <= s->size - 1)
	{
		if (s->num[i] > max)
			max = s->num[i];
		i++;
	}
	return (max);
}

void	solve_3(t_stack *s)
{
	int	max;

	max = find_max(s);
	if (max == s->num[1])
		rra(s);
	else if (max == s->num[2])
		ra(s);
	if (check_sort(s) != 1)
		sa(s);
}

void	solve4_5(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i <= 1)
	{
		check_if_closer_to_top(a, b, i);
		i++;
	}
	solve_3(a);
	while (b->size > 0)
		pa(a, b);
}

void	solve_small(t_stack *a, t_stack *b)
{
	if (check_sort(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		solve_3(a);
	else
		solve4_5(a, b);
}
