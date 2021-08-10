/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 09:23:46 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/09 15:18:24 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

/*
**	Doubly linked-list
*/
typedef struct s_node
{
	long int		num;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	struct s_node	*a;
	struct s_node	*b;
	int				num_count;
	int				size_a;
	int				size_b;
	int				ac;
	char			**av;
}				t_stack;

void			error_exit(t_stack *stack);
void			leakfree_nodes(t_node *node);
void			free_struct(t_stack *stack);
void			handle_two_args(t_stack *stack);
int				validate_args(t_stack *stack);
int				check_duplicate(t_stack *stack);
int				check_digits(t_stack *s);
t_stack			*init_struct(t_stack *stack, int ac, char **av);



void check_arg(t_stack *s);

#endif