/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:20:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/10 14:46:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_args_to_a(t_stack *s, t_info *info)
{
	int	i;
	int	j;
	
	i = 0;
	s->size = info->stack_size;
	while (i < info->stack_size)
	{
		j = i + 1;
		if (info->stack_size == 1)
			j = 0;
		s->num[i] = ft_atol(info->av[j]);
		printf("%ld\n", s->num[i]);
		i++;
	}
}

t_stack	*allocate_stack(t_info *info)
{
	t_stack	*tab;

	tab = ft_calloc(1, sizeof(t_stack));
	tab->num = ft_calloc((size_t)info->stack_size, sizeof(int));
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
	add_args_to_a(stack->a, info);
}
