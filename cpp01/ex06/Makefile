# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 11:37:43 by rsoo              #+#    #+#              #
#    Updated: 2023/08/24 11:38:01 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
CPP_FILES = main.cpp Harl.cpp
HPP_FILES = Harl.hpp
OBJ_DIR = objects
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(CPP_FILES:.cpp=.o))
RM = rm -rf

$(OBJ_DIR)/%.o: %.cpp $(HPP_FILES)
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
