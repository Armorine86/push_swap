/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:03:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/17 14:35:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void print_stacks(t_stack *a, t_stack *b, t_stack *c)
{
	int i;

	i = a->size - 1;
	while (i >= 0)
		printf("\nStack A: %d", a->num[i--]);
	printf("\nStack A Size = %d\n", a->size);
	i = b->size - 1;
	while (i >= 0)
		printf("\nStack B: %d", b->num[i--]);
	printf("\nStack B Size = %d\n", b->size);
	i = c->size - 1;
	while (i >= 0)
		printf("\nStack C: %d", c->num[i--]);
	printf("\nStack C Size = %d\n", c->size);
}

void	execute_sorting(t_stack *a, t_stack *b, t_stack *c)
{
	sa(a);
	print_stacks(a, b, c);
}