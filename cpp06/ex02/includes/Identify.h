/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:05:22 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/28 15:38:28 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_H
#define IDENTIFY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "Base.hpp"
#include "Classes.hpp"

#define RED 	"\e[0;31m"
#define GREEN 	"\e[0;32m"
#define YELLOW 	"\e[0;33m"
#define BLUE 	"\e[0;34m"
#define PURPLE 	"\e[0;35m"
#define CYAN 	"\e[0;36m"
#define WHITE 	"\e[0;37m"
#define RESET 	"\e[0m"

//Regular bold text
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BPUR "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UPUR "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

#endif

