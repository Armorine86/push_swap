/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:53:53 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/27 13:38:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		solve_b(s);
}
