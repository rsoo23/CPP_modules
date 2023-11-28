/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:00:20 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/02 23:00:20 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"

int main(int ac, char **av) {
    if (ac == 2) {
        ScalarConverter::convert(av[1]);
        return 0;
    }
    std::cout << URED "Error: only one argument allowed" RESET << std::endl;
    return 1;
}
