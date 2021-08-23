/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:03:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/23 15:21:57 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	split_B_bigger(t_stack *a, t_stack *b, int average)
{

}

void	split_A_smaller(t_stack *a, t_stack *b,	int average)
{
	if (a->size <= average)
		return ;
	if (a->num[a->size - 1] <= average)
		pb(a, b);
	ra(a);
	split_A_smaller(a, b, average);
}

void	solve_B(t_stack *a, t_stack *b)
{
	int	max;
	
	if (b->size == 0)
		return ;
	max = find_max(b);
	split_B_bigger(a, b, find_average(b));
	solve_B(a, b);
}

void	solve_big(t_stack *a, t_stack *b, t_stack *c)
{
	if (check_sort(a))
		return ;
	split_A_smaller(a, b, find_average(a));
	//print_stack(a, b, c);
	solve_B(a, b);
	//print_stack(a, b, c);
	//solve_big(a, b, c);
	c->size = c->size;
}
