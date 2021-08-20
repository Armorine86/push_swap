/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:25:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/20 11:15:21 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rotate(t_stack *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->num[0];
	while (i < s->size - 1)
	{
		s->num[i] = s->num[i + 1];
		i++;
	}
	s->num[s->size - 1] = tmp;
}

/*
*	Shift down all elements of stack A by 1. The last element becomes
*	the first one.
*/
void	rra(t_stack *a)
{
	if (a->size >= 2)
		rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

/*
*	Shift down all elements of stack B by 1. The last element becomes
*	the first one.
*/
void	rrb(t_stack *b)
{
	if (b->size >= 2)
		rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

/*
*	Shift down all elements of both stack A and B by 1. The last element becomes
*	the first one.
*/
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd("rrr\n", 1);
}
