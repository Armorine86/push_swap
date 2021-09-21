# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by mmondell          #+#    #+#              #
#    Updated: 2021/09/21 08:13:22 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= push_swap

## ----- NAME OF THE BONUS PART ----- ##
B_NAME			= checker

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		= srcs/
B_SRCS_DIR		= srcs/checker/

OBJ_DIR			= obj/

INCLUDE_DIR		= includes/

LIBFT_DIR		= libft/

## ----- SOURCE FILES ----- ##
SRCS_FILES		= push_swap.c validate_args.c utils.c build_stacks.c sort_big.c	 \
				  op_swap.c op_push.c op_rotate.c op_rev_rotate.c quicksort.c	 \
			 	  sort_small.c sort_utils.c utils2.c sort_utils2.c sort_big2.c	 \
				  utils3.c
## ----- BONUS SOURCE FILES ----- ##
B_SRCS_FILES	= checker.c validate_args.c utils.c build_stacks.c sort_big.c	 \
				  op_swap.c op_push.c op_rotate.c op_rev_rotate.c quicksort.c	 \
			 	  sort_small.c sort_utils.c utils2.c sort_utils2.c sort_big2.c	 \
				  utils3.c

## ----- .C TO .O CONVERT ----- ##
OBJ_FILES		= $(SRCS_FILES:.c=.o)
B_OBJ_FILES		= $(B_SRCS_FILES:.c=.o)

## ----- ADDPREFIX TO FILES ----- ##
# MAIN PROGRAMM #
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
VPATH			= $(SRCS_DIR) $(B_SRCS_DIR)

# BONUS PART #
B_SRCS			= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
B_OBJS			= $(addprefix $(OBJ_DIR), $(B_OBJ_FILES))

#--------------------------------------------------------------#

## ----- TOOLS AND COLORS ----- ##
RM				= rm -Rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

LIBFT			= $(MAKE) bonus -C $(LIBFT_DIR)

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##
all: obj $(NAME)
#	@echo "$(GREEN)Compilation Completed Successfully$(NORMAL)"

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDE_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	$(LIBFT)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

## ----- ACTIONS FOR THE BONUS PART ----- ##
bonus: $(B_NAME)
	@echo "$(GREEN)Bonus File Compiled!$(NORMAL)"

$(B_NAME): $(B_OBJS)
	$(LIBFT)
	$(CC) $(B_OBJS) -I$(INCLUDE_DIR) -L$(LIBFT_DIR) -lft -o $(B_NAME)

## ----- ACTION TO SUMMON THE VIZUALIZER ----- ##
viz:
	python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
## ----- CLEAN COMMANDS ----- ##
clean:
	$(RM) $(OBJS) $(B_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(RM) $(B_NAME) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean

re: fclean all bonus

.PHONY: all clean fclean re
