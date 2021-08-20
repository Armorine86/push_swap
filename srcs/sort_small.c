/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:28:23 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/20 12:13:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve4_5(t_stack *a, t_stack *b)
{
	
	a->size = a->size;
	b->size = b->size;
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

void	solve_small(t_stack *a, t_stack *b)
{
	//print_stack(a);
	if (check_sort(a) == 1)
		return ;
	//&print_stack(a);
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		solve_3(a);
	else
		solve4_5(a, b);
	//print_stack(a);
	b->size = b->size;
}
