/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:05:57 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/09 14:35:51 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_struct(t_stack *stack, int ac, char **av)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_putendl_fd("\033[31mError", 0);
		exit(-1);
	}
	stack->ac = ac;
	stack->av = av;
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = NULL;
	stack = init_struct(stack, ac, av);
	if (ac >= 2)
	{
		if (!validate_args(stack))
			error_exit(stack);
	}
	else
		error_exit(stack);
	return (0);
}
