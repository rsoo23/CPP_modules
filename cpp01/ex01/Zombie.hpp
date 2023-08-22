/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:46:41 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/22 09:49:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define BLACK 	"\e[0;30m"
#define RED 	"\e[0;31m"
#define GREEN 	"\e[0;32m"
#define YELLOW 	"\e[0;33m"
#define BLUE 	"\e[0;34m"
#define PURPLE 	"\e[0;35m"
#define CYAN 	"\e[0;36m"
#define WHITE 	"\e[0;37m"
#define RESET 	"\e[0m"

class Zombie {
    public:
        Zombie( std::string name );
        ~Zombie( void );

        void    announce( void );

    private:
        std::string name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif
