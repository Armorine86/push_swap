/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:47:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/11 15:03:16 by mmondell         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	pw	*stack;
	int	stack_size;
	int	free_me;

	free_me = 0;
	stack = NULL;
	argv++;
	if (argc < 2)
		error_exit();
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		free_me++;
	}
	stack_size = get_stacksize(argc, argv);
	if (!validate_args(argv, stack_size))
		error_exit();
	if (free_me)
		free_tab(argv);
	//printf("stack_size = %d\n", stack_size);
	return (0);
}