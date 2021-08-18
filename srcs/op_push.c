/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:16:41 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/18 11:35:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pull(t_stack *s)
{
	int	i;

	i = s->num[s->size - 1];
	s->size--;
	return (i);
}

void	push(t_stack *s, int n)
{
	s->num[s->size] = n;
	s->size++;
}

/*
*	Take the first element at the top of B and push it to the top of A
*/
void	pa(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		push(a, pull(b));
	ft_putstr_fd("pa\n", 1);
}

/*
*	Take the first element at the top of A and push it to the top of B
*/
void	pb(t_stack *b, t_stack *a)
{
	if (a->size != 0)
		push(b, pull(a));
	ft_putstr_fd("pb\n", 1);
}
