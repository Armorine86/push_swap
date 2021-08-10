/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:20:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/10 12:33:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*allocate_stack(t_info *info)
{
	t_stack *tab;

	tab = ft_calloc(1, sizeof(t_stack));
	tab->num = ft_calloc((int)info->stack_size, sizeof(int));
	if (!tab->num)
	{
		free(tab->num);
		free(tab);
	}
	tab->size = 0;
	return (tab);
}

void	build_stacks(t_push_swap *stack, t_info *info)
{
	stack->a = allocate_stack(info);
	stack->b = allocate_stack(info);
	stack->swap = allocate_stack(info);
	if (!stack->a || !stack->b || !stack->swap)
		free_all_exit(info, stack);
}