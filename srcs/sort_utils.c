/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/24 08:17:06 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_index(t_stack *s, int num)
{
	int	i;

	i = 0;
	while (i <= s->size - 1)
	{
		if (s->num[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

bool	closer_to_top(t_stack *s, int num)
{
	if (find_index(s, num) > s->size / 2)
		return (true);
	return (false);
}

void	rank_stacks(t_stack *a, t_stack *c)
{
	int	i;

	i = 0;
	while (i <= c->size - 1)
	{
		a->num[i] = find_index(c, a->num[i]);
		i++;
	}
}

int	find_average(t_stack *s)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i <= s->size - 1)
	{
		total += s->num[i];
		i++;
	}
	return ((float)total / (s->size - 1) + 0.5f);
}
