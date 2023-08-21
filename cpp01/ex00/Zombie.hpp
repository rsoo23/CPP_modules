/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:40:24 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/21 23:40:24 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    public:
        Zombie( void );
        ~Zombie( void );

        void    announce( void );
        Zombie* newZombie( std::string name );
        void    randomChump( std::string name );

    private:
        std::string name;
}

#endif
