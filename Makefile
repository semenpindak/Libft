# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oem <oem@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 19:50:03 by oem               #+#    #+#              #
#    Updated: 2020/10/31 15:42:50 by oem              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

INC_DIR := includes
SRC_DIR := sources
OBJ_DIR := objects

SRC_DIR_PRF := sources/ft_printf
OBJ_DIR_PRF := objects/ft_printf

INCLS	:= $(INC_DIR)
SRCS	:= $(wildcard $(SRC_DIR)/*.c)
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_PRF:= $(wildcard $(SRC_DIR_PRF)/*.c)
OBJ_PRF	:= $(SRCS_PRF:$(SRC_DIR_PRF)/%.c=$(OBJ_DIR_PRF)/%.o)

CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra

all:	obj
		$(MAKE) $(NAME)

obj:
		mkdir $(OBJ_DIR)
		mkdir $(OBJ_DIR_PRF)

$(NAME): $(OBJS) $(OBJ_PRF)
		ar rcs $(NAME) $(OBJS) $(OBJ_PRF)
		ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -g -MD -c $< -o $@ -I./$(INCLS)
include $(wildcard *.d)

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
