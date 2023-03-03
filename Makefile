# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 22:20:29 by htalhaou          #+#    #+#              #
#    Updated: 2023/03/03 22:51:17 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = check_arguments.c \
		main.c \
		opration.c \
		operation_utils.c \
		operation_utils_ab.c \
		check_args.c \
		stack.c \
		sorting_3numbers.c \
		sort_five.c \
		sort_100.c \

SRCS_BONUS = bonus/checker_bonus.c \
		bonus/check_args_bonus.c \
		bonus/check_arguments_bonus.c \
		bonus/operation_utils_bonus.c \
		bonus/operation_utils_ab_bonus.c \
		bonus/opration_bonus.c \
		bonus/stack_bonus.c \
		
NAME = push_swap

NAME_BONUS = checker

OBJS = $(SRCS:c=o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra 

RM = rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all = $(NAME)

$(NAME):$(OBJS)
	@make -C ./libft/
	@make bonus -C ./libft/
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

bonus:$(NAME_BONUS)

$(NAME_BONUS):$(OBJS_BONUS)
	@make -C ./libft/
	@make bonus -C ./libft/
	$(CC) $(CFLAGS) $(OBJS_BONUS)  libft/libft.a -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make fclean -C libft/
	$(RM) $(OBJS) $(NAME) $(OBJS_BONUS) $(NAME_BONUS)

re:fclean all

.PHONY:fclean all clean re