/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:41:23 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/18 15:27:38 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *s, int first, int last)
{
	int	tmp;
	
	tmp = s->num[first];
	s->num[first] = s->num[last];
	s->num[last] = tmp;
}

int	partition(t_stack *s, int first, int last)
{
	int	i;
	int	index;
	int	pivot;

	index = first;
	i = first;
	pivot = s->num[last];
	while (i < last)
	{
		if (s->num[i] < pivot)
		{
			swap(s, s->num[i], s->num[index]);
			index++;
		}
		i++;
		swap(s, s->num[last], s->num[index]);
	}
	return (index);
}

void	sort_recurse(t_stack *s, int first, int last)
{
	int	index;
	
	if (first < last)
	{
		index = partition(s, first, last);
		sort_recurse(s, first, index - 1);
		sort_recurse(s, index + 1, last);
	}
}

void	quicksort(t_stack *s)
{
	sort_recurse(s, 0, s->size - 1);  //! Bug avec le sorting.. 9 disparait du stack une fois sorté.
}