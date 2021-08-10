/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:20:50 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/09 15:18:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void check_arg(t_stack *s)
{
	int i = 1;
	int j = 0;
	
	if (s->ac == 2)
		i = 0;
	while (i < s->ac)
	{
		j = 0;
		while (s->av[i][j])
		{
			write(1, &s->av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}*/

void	handle_two_args(t_stack *stack)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(stack->av[1], ' ');
	while (tmp[i])
		i++;
	stack->num_count = i;
	stack->av = tmp;
	if (!check_digits(stack))
		error_exit(stack);
	ft_memcpy(stack->av, tmp, ft_strlen(*tmp));
	free(tmp);
	//check_arg(stack);
}


int	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	if (stack->ac == 2)
		i = 0;
	while (i < stack->ac)
	{
		j = i + 1;
		tmp = ft_atoi(stack->av[i]);
		while (j < stack->ac)
		{
			if (tmp == ft_atoi(stack->av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_digits(t_stack *s)
{
	int i;
	int j;

	i = 1;
	if (s->ac == 2)
		i = 0;
	while (i < s->num_count)
	{
		j = 0;
		if (s->av[i][j] == '-' || s->av[i][j] == '+')
			j++;
		while (s->av[i][j])
		{
			if (!ft_isdigit(s->av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_args(t_stack *stack)
{
	
	if (stack->ac > 2)
	{
		stack->num_count = stack->ac;
		if (!check_digits(stack))
			error_exit(stack);
		stack->num_count--;
	}
	else if (stack->ac == 2)
		handle_two_args(stack);
	if (!check_duplicate(stack))
		error_exit(stack);
	return (1);
}
