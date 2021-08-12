/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:01:05 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/11 21:04:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*int	argv_to_stack(t_stack *a, t_stack *c, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		c->num[i] = ft_atoi(argv[i++]);
	while (i > 0)
		a->num[i] = c->num[i--];
}*/

t_stack	*allocate_stack(int size)
{
	t_stack	*tab;

	tab = ft_calloc(1, sizeof(t_stack));
	if (!tab)
		return (NULL);
	tab->num = ft_calloc((size_t)size, sizeof(int));
	if (!tab->num)
	{
		free(tab->num);
		free(tab);
		error_exit();
	}
	tab->size = 0;
	return (tab);
}

int	build_stacks(t_pw *stack, /*char **argv,*/ int size)
{
	stack->a = allocate_stack(size);
	stack->b = allocate_stack(size);
	stack->c = allocate_stack(size);
	if (!stack->a || !stack->b || !stack->c)
	{
		free_stacks(stack);
		return (1);
	}
	/*if (!argv_to_stack(stack->a, stack->c, argv))
		return (1);*/
	return (0);
}