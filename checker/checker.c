/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:27:32 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/31 15:27:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	exit_ko(void)
{
	ft_putstr_fd("KO", 1);
	exit (1);
}

void	free_line(char *line)
{
	free (line);
	line = NULL;
}

bool	validate_operations(t_pw *s, char *line)
{
	if (!ft_strcmp(line, "pa"))
		pa(s->a, s->b);
	else if (!ft_strcmp(line, "pb"))
		pb(s->a, s->b);
	else if (!ft_strcmp(line, "sa"))
		sa(s->a);
	else if (!ft_strcmp(line, "sb"))
		sb(s->b);
	else if (!ft_strcmp(line, "ss"))
		ss(s->a, s->b);
	else if (!ft_strcmp(line, "ra"))
		ra(s->a);
	else if (!ft_strcmp(line, "rb"))
		rb(s->b);
	else if (!ft_strcmp(line, "rr"))
		rr(s->a, s->b);
	else if (!ft_strcmp(line, "rra"))
		rra(s->a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(s->b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(s->a, s->b);
	else
		return (false);
	return (true);
}

void	validate_push_swap(t_pw *s)
{
	char	moves[4];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = i;
		i += read(0, moves + i, 1);
		if (j == i)
			break ;
		if (moves[i] == '\n')
		{
			moves[j] = 0;
			if (!validate_operations(s, moves))
				exit_ko();
			i = 0;
		}
	}
	if (i == 4)
		exit_ko();
	if (check_sort(s->a))
		ft_putstr_fd("OK", 1);
}

int	main(int argc, char **argv)
{
	t_pw	stack;
	int		s_size;
	int		free_me;

	free_me = 0;
	if (argc < 2)
		exit (0);
	argv++;
	if (argc == 2)
		argv = split_argv(argv[0], &free_me);
	s_size = get_stacksize(argc, argv);
	if (validate_args(argv, s_size) || build_stacks(&stack, s_size))
		error_exit();
	if (!check_sort(stack.a))
		validate_push_swap(&stack);
	if (free_me)
		free_tab(argv);
	free_all_exit(&stack);
	return (0);
}
