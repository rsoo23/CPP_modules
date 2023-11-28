/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:03:18 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/28 13:35:03 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

typedef struct Data {
	std::string name;
	int height;
	int weight;
	int age;
}	Data;

class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer( const Serializer& other );
        Serializer& operator=( const Serializer& other );
        ~Serializer();
};

#endif
