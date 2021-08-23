/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:01:05 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/23 08:26:47 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*allocate_stack(int size)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	if (!s)
		return (NULL);
	s->num = ft_calloc((size_t)size, sizeof(int));
	if (!s->num)
		return (ft_free(s));
	s->size = 0;
	return (s);
}

int	build_stacks(t_pw *stack, int size)
{
	stack->a = allocate_stack(size);
	stack->b = allocate_stack(size);
	stack->c = allocate_stack(size);
	if (!stack->a || !stack->b || !stack->c)
		return (1);
	return (0);
}
