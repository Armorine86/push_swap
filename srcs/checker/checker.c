/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:27:32 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/01 12:02:36 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	exit_ko(t_pw *s)
{
	ft_putstr_fd("\033[31m\nKO\033[0m", 1);
	free_all_exit(s);
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
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0 || line != 0)
	{
		if (!line)
			break ;
		if (!validate_operations(s, line))
			break ;
		free_line(line);
	}
	free_line(line);
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
	argv_to_stack(&stack, argv, s_size);
	validate_push_swap(&stack);
	if (!check_sort(stack.a))
		exit_ko(&stack);
	else
		ft_putstr_fd("\033[32m\nOK\033[0m", 1);
	if (free_me)
		free_tab(argv);
	free_all_exit(&stack);
	return (0);
}
