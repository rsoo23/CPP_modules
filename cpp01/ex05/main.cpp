/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:04:30 by rsoo              #+#    #+#             */
/*   Updated: 2023/08/24 11:29:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main( void ) {
	Harl harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
}
