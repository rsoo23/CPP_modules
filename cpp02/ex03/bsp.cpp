/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:59:12 by rsoo              #+#    #+#             */
/*   Updated: 2023/09/13 09:26:31 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

static Fixed absoluteVal(Fixed val) {
    if (val >= 0) 
        return (val);
    return (val * Fixed(-1));
}

static Fixed areaOfTriangle(Point const p1, Point const p2, Point const p3) {
    return (Fixed(0.5f) * absoluteVal(p1.getXCoord() * (p2.getYCoord() - p3.getYCoord()) \
                                    + p2.getXCoord() * (p3.getYCoord() - p1.getYCoord()) \
                                    + p3.getXCoord() * (p1.getYCoord() - p2.getYCoord())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = areaOfTriangle(a, b, c); 
    Fixed areaPBC = areaOfTriangle(point, b, c);
    Fixed areaAPC = areaOfTriangle(a, point, c);
    Fixed areaABP = areaOfTriangle(a, b, point);
    Fixed areaSum = areaPBC + areaAPC + areaABP;

    if (areaABC == 0) {
        std::cout << RED << "Error: Triangle ABC cannot have area of 0" << RESET << std::endl;
    } else if (areaSum == areaABC && areaPBC != 0 && areaAPC != 0 && areaABP != 0) {
        return (true);
    } else if (areaSum > areaABC) {
        std::cout << RED << "The point lies outside the triangle" << RESET << std::endl;
    } else if (areaPBC == areaABC || areaAPC == areaABC || areaABP == areaABC) {
        std::cout << RED << "The point lies on a vertex of the triangle" << RESET << std::endl;
    } else {
        std::cout << RED << "The point lies on an edge of the triangle" << RESET << std::endl;
    }
    return (false);
}