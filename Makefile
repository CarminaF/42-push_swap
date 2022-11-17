# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 21:39:45 by cfamilar          #+#    #+#              #
#    Updated: 2022/11/15 19:57:36 by cfamilar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT_PATH	=	./libraries/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

SRCS_DIR	=	sources
INC_DIR		=	includes
OBJS_DIR	=	objects

HEADER		=	$(INC_DIR)/push_swap.h 
SRCS		=	$(SRCS_DIR)/check.c \
				$(SRCS_DIR)/cost.c \
				$(SRCS_DIR)/error.c \
				$(SRCS_DIR)/free.c \
				$(SRCS_DIR)/index.c \
				$(SRCS_DIR)/linked_list.c \
				$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/move.c \
				$(SRCS_DIR)/position.c \
				$(SRCS_DIR)/push_operations.c \
				$(SRCS_DIR)/push_swap.c \
				$(SRCS_DIR)/reverse_rotate_operations.c \
				$(SRCS_DIR)/rotate_operations.c \
				$(SRCS_DIR)/sort.c \
				$(SRCS_DIR)/stack.c \
				$(SRCS_DIR)/swap_operations.c \

OBJS		=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS_DIR) $(OBJS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
					$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJS_DIR):
					mkdir -p $(OBJS_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft