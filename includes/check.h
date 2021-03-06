/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:28:07 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/31 14:09:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "../includes/push_swap.h"

t_stack	*allocate_stack(int size);
int		get_stacksize(int argc, char **argv);
int		validate_args(char **argv, int size);
int		check_digits(char **argv, int size);
int		check_duplicate(char **argv, int size);
int		build_stacks(t_pw *stack, int size);
char	**split_argv(char *str, int *free_me);
bool	check_sort(t_stack *s);
void	argv_to_stack(t_pw *s, char **argv, int size);

#endif
