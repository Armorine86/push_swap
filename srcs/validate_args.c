/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:31:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/30 13:25:49 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **argv, int size)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		tmp = ft_atol(argv[i]);
		if (tmp < (long)INT_MIN || tmp > (long)INT_MAX)
			return (1);
		while (j < size)
		{
			if (tmp == ft_atol(argv[j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_digits(char **argv, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(char **argv, int size)
{
	if (check_digits(argv, size) || check_duplicate(argv, size))
		return (1);
	return (0);
}
