/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:53:53 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/26 12:52:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_rest(t_pw *s)
{
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

void	push_next_half(t_pw *s, int max)
{
	while (top(s->a) <= max && (top(s->a) != 0))
	{
		if (top(s->a) == bot(s->a) + 1)
			ra(s->a);
		else
			pb(s->a, s->b);
	}
	if (find_min(s->b) == bot(s->a) + 1)
		solve_B(s);
}
