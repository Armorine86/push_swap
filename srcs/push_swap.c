/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:47:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/01 10:12:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pw	stack;
	int		stack_size;
	int		free_me;

	free_me = 0;
	if (argc < 2)
		exit (0);
	argv++;
	if (argc == 2)
		argv = split_argv(argv[0], &free_me);
	stack_size = get_stacksize(argc, argv);
	if (validate_args(argv, stack_size) || build_stacks(&stack, stack_size))
		error_exit();
	argv_to_stack(&stack, argv, stack_size);
	if (!check_sort(stack.a))
	{
		if (stack_size > 6)
			solve_big(&stack);
		else
			solve_small(&stack);
	}
	if (free_me)
		free_tab(argv);
	free_all_exit(&stack);
}
