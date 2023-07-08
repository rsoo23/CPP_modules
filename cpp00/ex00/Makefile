# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 18:07:12 by rsoo              #+#    #+#              #
#    Updated: 2023/07/08 18:50:51 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPP_FILES = megaphone.cpp
RM = rm -rf

all: $(NAME)

$(NAME): $(CPP_FILES)
	$(CC) $(CFLAGS) $(CPP_FILES) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean all
