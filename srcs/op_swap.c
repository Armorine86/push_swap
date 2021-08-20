/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:28:01 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/20 14:07:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_swap(t_stack *s)
{
	int	tmp;
	int	i;

	i = s->size - 1;
	tmp = s->num[i];
	s->num[i] = s->num[i - 1];
	s->num[i - 1] = tmp;
}

/*
*	Swap the first two elements at the top of Stack A
*/
void	sa(t_stack *a)
{
	if (a->size >= 2)
		op_swap(a);
	ft_putstr_fd("sa\n", 1);
}

/*
*	Swap the first two elements at the top of Stack B
*/
void	sb(t_stack *b)
{
	if (b->size >= 2)
		op_swap(b);
	ft_putstr_fd("sb\n", 1);
}

/*
*	Swap the first two elements at the top of Stack A && Stack B
*/
void	ss(t_stack *a, t_stack *b)
{
	op_swap(a);
	op_swap(b);
	ft_putstr_fd("ss\n", 1);
}
