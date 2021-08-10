/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:05:57 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/10 14:15:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_info	*init_struct(t_info *info, int ac, char **av)
{
	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		error_exit();
	info->ac = ac;
	info->av = av;
	return (info);
}

int	main(int ac, char **av)
{
	t_push_swap	stack;
	t_info		*info;

	info = NULL;
	if (ac < 2)
		return (0);
	info = init_struct(info, ac, av);
	if (!info)
		error_exit();
	validate_args(info);
	build_stacks(&stack, info);
	free_all_exit(info, &stack);
}
