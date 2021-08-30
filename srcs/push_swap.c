/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:47:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/30 10:11:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_and_rank(t_stack *a, t_stack *c)
{
	quicksort(c);
	rank_stacks(a, c);
}

char	**split_argv(char *str, int *free_me)
{
	char	**ret;

	ret = ft_split(str, ' ');
	*free_me = 1;
	return (ret);
}

void	argv_to_stack(t_pw *s, char **argv, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = size - 1;
	j = 0;
	while (i >= 0)
	{
		tmp = ft_atoi(argv[j]);
		s->c->num[i] = tmp;
		s->c->size++;
		i--;
		j++;
	}
	i = size - 1;
	while (i >= 0)
	{
		s->a->num[i] = s->c->num[i];
		s->a->size++;
		i--;
	}
	if (s->a->size > 3)
		sort_and_rank(s->a, s->c);
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
