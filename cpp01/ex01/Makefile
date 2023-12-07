# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 09:47:07 by rsoo              #+#    #+#              #
#    Updated: 2023/08/22 10:39:49 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moar_brainz
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
CPP_FILES = main.cpp Zombie.cpp zombieHorde.cpp
OBJ_DIR = objects
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(CPP_FILES:.cpp=.o))
RM = rm -rf

$(OBJ_DIR)/%.o: %.cpp
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
