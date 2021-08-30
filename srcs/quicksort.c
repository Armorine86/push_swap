/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:41:23 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/30 13:25:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s, int left, int right)
{
	int	tmp;

	tmp = s->num[left];
	s->num[left] = s->num[right];
	s->num[right] = tmp;
}

int	partition(t_stack *s, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (s->num[left] < pivot)
			left++;
		while (s->num[right] > pivot)
			right--;
		if (left <= right)
		{
			swap(s, left, right);
			left++;
			right--;
		}
	}
	return (left);
}

void	sort_recurse(t_stack *s, int left, int right)
{
	int	index;
	int	pivot;

	pivot = s->num[(left + right) / 2];
	if (left < right)
	{
		index = partition(s, left, right, pivot);
		sort_recurse(s, left, index - 1);
		sort_recurse(s, index, right);
	}
}

/*
*	credits: https://www.youtube.com/watch?v=SLauY6PpjW4
*	Well explained Quicksort implementation.
*		**Modified for a reverse array**
*/
void	quicksort(t_stack *s)
{
	int	left;
	int	right;

	left = 0;
	right = s->size - 1;
	sort_recurse(s, left, right);
}
