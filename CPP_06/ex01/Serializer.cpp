/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:29 by ancolmen          #+#    #+#             */
/*   Updated: 2024/01/19 19:31:40 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*::: CONSTRUCTORS :::*/

Serializer::Serializer() {}

/*::: DESTRUCTORS :::*/

Serializer::~Serializer() {}

/*::: MEMBER FUNCTIONS :::*/

uintptr_t Serializer::serialize(Data* ptr) {

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {

	return (reinterpret_cast<Data*>(raw));
}