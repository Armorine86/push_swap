/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:23:46 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/10 14:43:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
typedef struct s_stack
{
	long	*num;
	int		size;
}				t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*swap;
}				t_push_swap;

typedef struct s_info
{
	int		stack_size;
	int		ac;
	char	**av;
}			t_info;

t_stack			*allocate_stack(t_info *info);
void			error_exit(void);
void			free_table(char **tab);
void			free_struct(t_info *info);
void			free_all_exit(t_info *info, t_push_swap *stack);
void			build_stacks(t_push_swap *stack, t_info *info);
int				validate_args(t_info *info);
int				check_duplicate(t_info *info);
int				check_digits(t_info *s);
t_info			*init_struct(t_info *info, int ac, char **av);

void			check_arg(t_info *s);

#endif