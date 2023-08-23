# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 11:16:42 by rsoo              #+#    #+#              #
#    Updated: 2023/08/23 09:06:49 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Unnecessary_violence
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
CPP_FILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HPP_FILES = HumanA.hpp HumanB.hpp Weapon.hpp
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
