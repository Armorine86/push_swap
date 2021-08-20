/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:41:23 by mmondell          #+#    #+#             */
/*   firstdated: 2021/08/20 12:12:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *s, int last, int first)
{
	int	tmp;
	
	tmp = s->num[last];
	s->num[last] = s->num[first];
	s->num[first] = tmp;
}

int	partition(t_stack *s, int last, int first, int pivot)
{
	while (last <= first)
	{
		while (s->num[last] > pivot)
			last++;
		while (s->num[first] < pivot)
			first--;
		if (last <= first)
		{
			swap(s, last, first);
			last++;
			first--;
		}
	}
	return (last);
}

void	sort_recurse(t_stack *s, int last, int first)
{
	int	index;
	int	pivot;
	
	pivot = s->num[(last + first) / 2];
	if (last < first)
	{
		index = partition(s, last, first, pivot);
		sort_recurse(s, last, index - 1);
		sort_recurse(s, index, first);
	}
}

/*
*	credits: https://www.youtube.com/watch?v=SLauY6PpjW4
*	Well explained Quicksort implementation.
*		**Modified for a reverse array**
*/
void	quicksort(t_stack *s)
{
	int	last;
	int	first;

	last = 0;
	first = s->size - 1;
	sort_recurse(s, last, first);
}