/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:03:26 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/19 15:20:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	solve(t_stack *a, t_stack *b, t_stack *c)
{
	//print_stacks(a, b, c);
	print_stack(a);
	quicksort(c);
	print_stack(a);
	print_stack(b);
}
