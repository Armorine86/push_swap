/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:20:50 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/10 12:16:16 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void check_arg(t_info *s)
{
	int i = 1;
	int j = 0;
	
	if (s->ac == 2)
		i = 0;
	while (i < s->stack_size)
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

int	check_duplicate(t_info *info)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	if (info->ac == 2)
		i = 0;
	else
		info->stack_size = info->ac;
	while (i < info->stack_size)
	{
		j = i + 1;
		tmp = ft_atoi(info->av[i]);
		while (j < info->stack_size)
		{
			if (tmp == ft_atoi(info->av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_digits(t_info *s)
{
	int	i;
	int	j;

	i = 1;
	if (s->ac == 2)
		i = 0;
	else
		s->stack_size = s->ac;
	while (i < s->stack_size)
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

int	validate_args(t_info *info)
{
	if (info->ac > 2)
	{
		if (!check_digits(info))
			error_exit();
		if (!check_duplicate(info))
			error_exit();
		info->stack_size = info->ac - 1;
	}
	else if (info->ac == 2)
	{
		info->av = ft_split(info->av[1], ' ');
		while (info->av[info->stack_size])
			info->stack_size++;
		if (!check_digits(info))
			error_exit();
		if (!check_duplicate(info))
			error_exit();
	}
	return (1);
}
