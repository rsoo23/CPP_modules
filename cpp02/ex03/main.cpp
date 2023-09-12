/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/12 11:31:17 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int main( void ) {
	Point a(0.0f , 0.0f);
	Point b(10.0f , 0.0f);
	Point c(0.0f , 10.0f);
	
	Point point(25.0f, 25.0f);
	
	std::cout << YELLOW << "TESTS: "<< std::endl;
	std::cout << CYAN << "	Point 1: " << RESET << "x: " << a.get_x_coord() << "y: " << a.get_y_coord() << std::endl;
	std::cout << GREEN << "	Point 2: " << RESET << "x: " << b.get_x_coord() << "y: " << b.get_y_coord() << std::endl;
	std::cout << BLUE << "	Point 3: " << RESET << "x: " << c.get_x_coord() << "y: " << c.get_y_coord() << std::endl;

	std::cout << PURPLE << "	Point 3: " << RESET << "x: " << point.get_x_coord() << "y: " << point.get_y_coord() << std::endl;

}
