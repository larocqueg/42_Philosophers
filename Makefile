# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 14:40:03 by gde-la-r          #+#    #+#              #
#    Updated: 2025/04/25 14:48:48 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = ./srcs
INCLUDES = ./includes

SRC= $(SRCS_DIR)/main.c \
	 $(SRCS_DIR)/utils.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME)
	@echo "Compilation completed!\n"

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean: $(OBJS)
	@rm -rf $(OBJS)
	@echo "Object files removed!\n"

fclean: $(NAME) $(OBJS)
	@rm -rf $(OBJS) $(NAME)
	@echo "Object files & $(NAME) removed!\n"

re:fclean
	@make all
	@echo "Rebuild completed!\n"

PHONY: all clean fclean re
