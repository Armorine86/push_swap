/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:27:32 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/31 11:06:55 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/check.h"

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

void	validate_operations(t_pw *s, char *line)
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
		exit_ko();
}

void	validate_push_swap(t_pw *s)
{
	char	*line;
	
	while (get_next_line(&line))
	{
		validate_operations(s, line);
		free_line(line);
	}
	free_line(line);
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