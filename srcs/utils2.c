/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:17:18 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/24 20:07:05 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	bot(t_stack *s)
{
	return (s->num[0]);
}

int	top(t_stack *s)
{
	return (s->num[s->size - 1]);
}

bool	check_smaller_than_average(t_stack *s, int average)
{
	int	i;

	i = 0;
	while (i <= s->size - 1)
	{
		if (s->num[i] < average)
			return (true);
		i++;
	}
	return (false);
}

bool	check_bigger_than_average(t_stack *s, int average)
{
	int	i;

	i = 0;
	while (i <= s->size - 1)
	{
		if (s->num[i] > average)
			return (true);
		i++;
	}
	return (false);
}
