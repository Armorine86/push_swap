/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:28:23 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/19 15:33:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		ra(s);
	else if (max == s->num[2])
		rra(s);
	if (!check_sort(s))
		sa(s);
}

void	solve_small(t_stack *a, t_stack *b)
{
	if (check_sort(a))
		return ;
	print_stack(a);
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		solve_3(a);
	print_stack(a);
	//else
	//	solve4_5(a, b);
	b->size = b->size;
}
