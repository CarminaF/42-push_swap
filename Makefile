# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 21:39:45 by cfamilar          #+#    #+#              #
#    Updated: 2022/12/01 20:56:16 by cfamilar         ###   ########.fr        #
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
				$(SRCS_DIR)/utils.c \

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

test2:				$(NAME)
					$(eval ARG = $(shell jot -r 2 0 200))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)
					$(eval ARG = $(shell jot -r 3 0 500))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)
					$(eval ARG = $(shell jot -r 5 0 5000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)
					$(eval ARG = $(shell jot -r 100 0 5000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)
					$(eval ARG = $(shell jot -r 500 0 1000000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l


.PHONY:				all clean fclean re libft test2 test3 test5 test100 test500