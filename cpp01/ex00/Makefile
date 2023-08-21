# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 23:37:27 by rsoo              #+#    #+#              #
#    Updated: 2023/08/21 23:37:27 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPP_FILES = Account.cpp
OBJ_FILES = $(CPP_FILES:.cpp=.o)
RM = rm -rf

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

