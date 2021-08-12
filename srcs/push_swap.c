/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:47:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/12 11:05:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (validate_args(argv, s_size) || build_stacks(&stack, /*argv,*/ s_size))
		error_exit();
	if (free_me)
		free_tab(argv);
	free_all_exit(&stack);

	//* I AM TRYING GIT BRANCHING 
}
