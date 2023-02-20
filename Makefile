# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 22:20:29 by htalhaou          #+#    #+#              #
#    Updated: 2023/02/20 22:38:54 by htalhaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #






SRCS = check_arguments.c \
		main.c \
		opration.c \
		operation_utils.c \
		operation_utils_ab.c \
		ascending.c \
		stack.c \
		sorting_3numbers.c \
		sort_five.c \
		sort_100.c \

NAME = push_swap

OBJS = $(SRCS:c=o)

CC = gcc

FLAGS = -Wall -Werror -Wextra 

RM = rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all = $(NAME)

$(NAME):$(OBJS)
	@make -C ./li/
	@make bonus -C ./li/
	$(CC) $(CFLAGS) $(OBJS) li/libft.a -o $(NAME)

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	@make fclean -C li/
	$(RM) $(OBJS) $(NAME)

re:fclean all

.PHONY:fclean all clean re
