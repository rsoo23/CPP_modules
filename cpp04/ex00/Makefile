# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 23:29:57 by rsoo              #+#    #+#              #
#    Updated: 2023/10/18 17:18:20 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes/
# CFLAGS += -fsanitize=address

CPP_FILES = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
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


