# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 21:52:24 by rsoo              #+#    #+#              #
#    Updated: 2023/08/07 22:04:42 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPP_FILES = phonebook.cpp
RM = rm -rf

all: $(NAME)

$(NAME): $(CPP_FILES)
	$(CC) $(CFLAGS) $(CPP_FILES) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean all
