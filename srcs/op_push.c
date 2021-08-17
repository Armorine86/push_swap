/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:16:41 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/17 13:17:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
*	Take the first element at the top of B and push it to the top of A
*/
void	pa(t_stack *a, t_stack *b)
{
	int tmp;
	
	if (b->size == 0)
		return;
	
}