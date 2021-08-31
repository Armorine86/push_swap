# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by mmondell          #+#    #+#              #
#    Updated: 2021/08/31 13:06:29 by mmondell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= push_swap

## ----- NAME OF THE BONUS PART ----- ##
B_NAME			= push_swap_checker

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		= srcs/
B_SRCS_DIR		= checker/

OBJ_DIR			= obj/

INCLUDE_DIR		= includes/

LIBFT_DIR		= libft/

## ----- SOURCE FILES ----- ##
SRCS_FILES		= push_swap.c validate_args.c utils.c build_stacks.c sort_big.c	 \
				  op_swap.c op_push.c op_rotate.c op_rev_rotate.c quicksort.c	 \
			 	  sort_small.c sort_utils.c utils2.c sort_utils2.c sort_big2.c	 \

## ----- BONUS SOURCE FILES ----- ##
B_SRCS_FILES	= checker.c validate_args.c utils.c build_stacks.c sort_big.c	 \
				  op_swap.c op_push.c op_rotate.c op_rev_rotate.c quicksort.c	 \
			 	  sort_small.c sort_utils.c utils2.c sort_utils2.c sort_big2.c	 \

## ----- .C TO .O CONVERT ----- ##
OBJ_FILES		= $(SRCS_FILES:.c=.o)
B_OBJ_FILES		= $(B_SRCS_FILES:.c=.o)

## ----- ADDPREFIX TO FILES ----- ##
# MAIN PROGRAMM #
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# BONUS PART #
B_SRCS			= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
B_OBJS			= $(addprefix $(B_OBJ_DIR), $(B_OBJ_FILES))

# LIBFT ARCHIVE #
LIBFT			= $(addprefix $(LIBFT_DIR), libft.a)
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

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##
all: obj $(LIBFT) $(NAME)
	@echo "$(GREEN)Compilation Completed Successfully$(NORMAL)"

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(OBJ_DIR)%.o:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIBFT) -I$(INCLUDE_DIR) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -lm -o $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

## ----- ACTIONS FOR THE BONUS PART ----- ##
bonus: b_obj all $(B_NAME)
	@echo "$(GREEN)Bonus File Compiled!$(NORMAL)"

$(B_OBJ_DIR)%.o:$(B_SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I$(LIBFT) -I$(INCLUDE_DIR) -o $@ -c $<

$(B_NAME): $(B_OBJS)
	$(CC) $(OBJS) $(B_OBJS) $(LIBFT) -lm -o $(B_NAME)
	
b_obj:
	@mkdir -p $(B_OBJ_DIR)
	
## ----- CLEAN COMMANDS ----- ##
clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(B_OBJ_DIR)
	@rm -f $(B_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(RM) $(B_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all bonus

.PHONY: all clean fclean re