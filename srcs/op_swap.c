/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:28:01 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/17 14:40:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;
	int	i;

	i = s->size - 1;
	if (s->size < 2)
		return;
	tmp = s->num[i];
	s->num[i] = s->num[i - 1];
	s->num[i - 1] = tmp;
}

/*
*	Swap the first two elements at the top of Stack A
*/
void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 0);
}

/*
*	Swap the first two elements at the top of Stack B
*/
void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 0);
}

/*
*	Swap the first two elements at the top of Stack A && Stack B
*/
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 0);
}
