/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:31:54 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/27 13:55:12 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_rotate(t_pw *s)
{
	pa(s->a, s->b);
	ra(s->a);
}

int	find_min(t_stack *s)
{
	int	i;
	int	min;

	min = bot(s);
	i = 0;
	while (i <= s->size - 1)
	{
		if (s->num[i] < min)
			min = s->num[i];
		i++;
	}
	return (min);
}
