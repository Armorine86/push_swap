# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 09:18:40 by mmondell          #+#    #+#              #
#    Updated: 2021/08/23 15:22:26 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
FLAGS	= -Wextra -Werror -Wall -g

GREEN = \033[32m
SRCS_DIR = ./srcs/
OBJ_DIR	= ./obj/
INC_DIR = ./include/
LIBFT_DIR = ./libft/

SRCS_FILES = push_swap.c validate_args.c utils.c build_stacks.c sort_big.c	 \
			 op_swap.c op_push.c op_rotate.c op_rev_rotate.c quicksort.c	 \
			 sort_small.c sort_utils.c utils2.c
				 
OBJ_FILES = $(SRCS_FILES:.c=.o)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

all: obj $(LIBFT) $(NAME)
	@echo "$(GREEN)Compilation Complete"

obj:
	@mkdir -p $(OBJ_DIR) $(LIBFT_OBJ)
$(OBJ_DIR)%.o:$(SRCS_DIR)%.c
	@gcc $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $< 
$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@gcc $(OBJ) $(LIBFT) -lm -o $(NAME)

viz:
	@python3 pyviz.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`

clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re