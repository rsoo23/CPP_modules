# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 00:01:02 by rsoo              #+#    #+#              #
#    Updated: 2023/09/14 00:01:02 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap3
CC = g++
CFLAGS = -Wall -Wextra -Werror -Wno-shadow -Wshadow -std=c++98 -fsanitize=address -g3
CPP_FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
HPP_FILES = *.hpp
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

