/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:14:50 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/30 13:24:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s)
{
	int	i;
	int	tmp;

	i = s->size - 1;
	tmp = s->num[i];
	while (i > 0)
	{
		s->num[i] = s->num[i - 1];
		--i;
	}
	s->num[0] = tmp;
}

/*
*	Shift up all elements of stack A by 1. The first element becomes
*	the last one.
*/
void	ra(t_stack *a)
{
	if (a->size >= 2)
		rotate(a);
	ft_putstr_fd("ra\n", 1);
}

/*
*	Shift up all elements of stack B by 1. The first element becomes
*	the last one.
*/
void	rb(t_stack *b)
{
	if (b->size >= 2)
		rotate(b);
	ft_putstr_fd("rb\n", 1);
}

/*
*	Shift up all elements of both stack A and B by 1. The first element becomes
*	the last one.
*/
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
}
