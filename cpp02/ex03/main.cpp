/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/12 23:48:48 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int main( void ) {
	Point a(0.0f , 0.0f);
	Point b(10.0f , 0.0f);
	Point c(0.0f , 10.0f);
	
	Point point(25.0f, 25.0f);
	
	std::cout << YELLOW << "TESTS: "<< std::endl;
	std::cout << CYAN << "Vertex 1: " << RESET << a << std::endl;
	std::cout << GREEN << "Vertex 2: " << RESET << b << std::endl;
	std::cout << BLUE << "Vertex 3: " << RESET << c << std::endl;

	std::cout << PURPLE << "Point to check: " << RESET << point << std::endl << std::endl;

	std::cout << YELLOW << "Result: ";

	if (bsp(a, b, c, point))
		std::cout << GREEN << "The point lies in the triangle" << std::endl;
}
