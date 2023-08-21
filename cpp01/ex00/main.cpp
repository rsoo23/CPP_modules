/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:38:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/21 23:38:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << "[stack] Please enter \e[0;32mzombie\e[0m name:" <<
    std::cin >> name;

    std::cout << "[heap] Please enter \e[0;32mzombie\e[0m name:" <<
    std::cin >> name;

    std::cout << "[chump] Please enter \e[0;32mzombie\e[0m name:" <<
    std::cin >> name;
}
