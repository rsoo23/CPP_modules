/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:10:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/07 21:49:48 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // header file library, let us works with input and output objects
#include <cctype> // toupper
// using namespace std; -> can be omitted and replaced with the std:: keyword

/*
newline: 
std::cout << "Hello world\n"; or
std::cout << "Hello world" << endl;

cout: console output
cin: console input
*/

int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			std::cout << (char)toupper(av[i][j]);
	}
	std::cout << std::endl;
	return 0;
}
