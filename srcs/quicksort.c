/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:41:23 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/19 08:58:45 by mmondell         ###   ########.fr       */
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

int	partition(t_stack *s, int first, int last, int pivot)
{
	while (first <= last)
	{
		while (s->num[first] < pivot)
			first++;
		while (s->num[last] > pivot)
			last--;
		if (first <= last)
		{
			swap(s, first, last);
			first++;
			last--;
		}
	}
	return (first);
}

void	sort_recurse(t_stack *s, int first, int last)
{
	int	index;
	int	pivot;
	
	pivot = s->num[(first + last) / 2];
	if (first < last)
	{
		index = partition(s, first, last, pivot);
		sort_recurse(s, first, index - 1);
		sort_recurse(s, index, last);
	}
}

/*
*	credits: https://www.youtube.com/watch?v=SLauY6PpjW4
*	Well explained Quicksort implementation.
*/
void	quicksort(t_stack *s)
{
	int	first;
	int	last;

	first = 0;
	last = s->size - 1;
	sort_recurse(s, first, last);
}