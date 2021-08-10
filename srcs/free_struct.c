/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:09:18 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/10 12:14:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *s)
{
	if (s)
		free(s->num);
	free(s);
}

void	free_all_exit(t_info *info, t_push_swap *stack)
{
	if (stack)
	{
		free_stack(stack->a);
		free_stack(stack->b);
		free_stack(stack->swap);
	}
	if (info->ac == 2)
		free_table(info->av);
	free(info);
	exit(0);
}
