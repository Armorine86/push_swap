/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:32:49 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/20 15:31:18 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


bool	check_sort(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < s->size - 1)
	{
		if (s->num[i] < s->num[j])
			return (false);
		i++;
		j++;
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


void	print_stack(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n---------  BOTTOM");
	while (i <= s->size - 1)
		printf("\n     %d     [%d]", s->num[i++], j++);
	printf("\n---------  TOP\n");
	printf(" Stack A\n\n");
	//printf("\nStack A Size = %d\n", s->size);
}