/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:32:49 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/24 08:32:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_sort(t_stack *s)
{
	int	i;
	int	j;

	i = 1;
	j = s->num[0];
	while (i <= s->size - 1)
	{
		if (s->num[i] > j)
			return (false);
		j = s->num[i++];
	}
	return (true);
}

void	free_all_exit(t_pw *s)
{
	free(s->a->num);
	free(s->a);
	free(s->b->num);
	free(s->b);
	free(s->c->num);
	free(s->c);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	error_exit(void)
{
	ft_putstr_fd("Error", 2);
	exit (EXIT_FAILURE);
}
