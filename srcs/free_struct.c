/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:09:18 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/09 13:01:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_nodes(t_node *node)
{
	t_node	*next;
	t_node	*tmp;

	if (node)
	{
		next = node->next;
		while (next != node)
		{
			tmp = next;
			next = next->next;
			free(tmp);
		}
		free(next);
	}
}

void	free_struct(t_stack *stack)
{
	if (stack)
	{
		if (stack->a)
			free_nodes(stack->a);
		if (stack->b)
			free_nodes(stack->b);
		free(stack);
	}
}
