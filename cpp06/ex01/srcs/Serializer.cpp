/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:03:09 by rsoo              #+#    #+#             */
/*   Updated: 2023/11/28 13:23:37 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

Serializer::Serializer() {}

Serializer::Serializer( const Serializer& other ) {
    (void)other;
}

Serializer& Serializer::operator=( const Serializer& other ) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
