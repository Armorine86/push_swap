/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:05:55 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/31 14:08:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_and_rank(t_stack *a, t_stack *c)
{
	quicksort(c);
	rank_stacks(a, c);
}

char	**split_argv(char *str, int *free_me)
{
	char	**ret;

	ret = ft_split(str, ' ');
	*free_me = 1;
	return (ret);
}

void	argv_to_stack(t_pw *s, char **argv, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = size - 1;
	j = 0;
	while (i >= 0)
	{
		tmp = ft_atoi(argv[j]);
		s->c->num[i] = tmp;
		s->c->size++;
		i--;
		j++;
	}
	i = size - 1;
	while (i >= 0)
	{
		s->a->num[i] = s->c->num[i];
		s->a->size++;
		i--;
	}
	if (s->a->size > 3)
		sort_and_rank(s->a, s->c);
}

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
