/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:01:05 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/18 14:35:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*allocate_stack(int size)
{
	t_stack	*tab;

	tab = ft_calloc(1, sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->num = ft_calloc((size_t)size, sizeof(int));
	if (!tab->num)
		return (ft_free(tab));
	tab->size = 0;
	return (tab);
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
