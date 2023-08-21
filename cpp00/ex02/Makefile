# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 11:02:18 by rsoo              #+#    #+#              #
#    Updated: 2023/08/13 11:02:18 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPP_FILES = Account.cpp tests.cpp
OBJ_FILES = $(CPP_FILES:.cpp=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
