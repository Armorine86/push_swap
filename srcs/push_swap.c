/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:47:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/18 14:36:54 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	argv_to_stack(t_stack *a, t_stack *c, char **argv, int size)
{
	int	i;
	int	tmp;

	i = size - 1;
	while (i >= 0)
	{
		tmp = ft_atoi(argv[i]);
		a->num[i] = tmp;
		a->size++;
		i--;
	}
	i = size - 1;
	while (i >= 0)
	{
		c->num[i] = a->num[i];
		c->size++;
		i--;
	}
}

int	get_stacksize(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argc > 2)
		i = argc - 1;
	return (i);
}

int	main(int argc, char **argv)
{
	t_pw	stack;
	int		s_size;
	int		free_me;

	free_me = 0;
	if (argc < 2)
		error_exit();
	argv++;
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		free_me++;
	}
	s_size = get_stacksize(argc, argv);
	if (validate_args(argv, s_size) || build_stacks(&stack, s_size))
		error_exit();
	argv_to_stack(stack.a, stack.c, argv, s_size);
	if (s_size > 6)
		solve(stack.a, stack.b, stack.c);
	//else
	//	solve_small(stack.a, stack.b);
	if (free_me)
		free_tab(argv);
	free_all_exit(&stack);
}
