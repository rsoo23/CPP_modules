# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 01:17:13 by rsoo              #+#    #+#              #
#    Updated: 2023/11/30 01:17:13 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easy_find
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes/
# CFLAGS += -fsanitize=address

CPP_FILES = main.cpp
HPP_FILES = *.hpp

INC_DIR = includes
SRCS_DIR = srcs
OBJ_DIR = objects

INCLUDES = $(addprefix $(INC_DIR)/, $(HPP_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(CPP_FILES:.cpp=.o))

RM = rm -rf

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.cpp $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
