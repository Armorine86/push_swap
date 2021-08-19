/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:32:49 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/19 15:19:51 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(t_stack *s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < s->size)
	{
		if (s->num[i] < s->num[j])
			return(0);
		i++;
		j++;
	}
	return (1);
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


void	print_stack(t_stack *s)
{
	int	i;

	i = s->size - 1;
	while (i >= 0)
		printf("\nStack A: %d", s->num[i--]);
	printf("\nStack A Size = %d\n", s->size);
}