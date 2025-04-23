/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:14:17 by asaux             #+#    #+#             */
/*   Updated: 2025/04/12 14:27:03 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data data("Data_test", 42);

	std::cout << "Original pointer: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized value : " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << deserialized << std::endl;

	std::cout << "Data values: ID = " << deserialized->getId()
			  << ", Name = " << deserialized->getName() << std::endl;

	if (deserialized == &data)
		std::cout << "✅ Pointeurs identiques !" << std::endl;
	else
		std::cout << "❌ Pointeurs différents !" << std::endl;

	return 0;
}
