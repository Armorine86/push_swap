/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:27:10 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/20 15:11:57 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	rank_stacks(t_stack *a, t_stack *c)
// {
// 	int	i;
// 	int	j;
	
// 	i = 0;
// 	while (i <= c->size - 1)
// 	{
// 		j = 0;
// 		while (a->num[i] != c->num[j])
// 			j++;
// 		a->num[i] = j;
// 		i++;
// 	}
// }

void	rank_stacks(t_stack *a, t_stack *c)
{
	int	i;
	
	i = 0;
	while (i <= c->size - 1)
	{
		a->num[i] = find_index(c, a->num[i]);
		i++;
	}
}
