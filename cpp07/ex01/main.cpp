/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:32:39 by asaux             #+#    #+#             */
/*   Updated: 2025/04/28 14:45:07 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T& elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void incrementElement(T& elem)
{
	++elem;
}

template <typename T>
void printConstElement(const T& elem)
{
	std::cout << elem << std::endl;
}

int main()
{
	int intArray[5] = {0, 1, 2, 3, 4};
	std::string strArray[3] = {"hello", "world", "!"};
	const int constArray[3] = {10, 20, 30};

	std::cout << "Int array before increment:" << std::endl;
	iter(intArray, 5, printElement);

	iter(intArray, 5, incrementElement);

	std::cout << "Int array after increment:" << std::endl;
	iter(intArray, 5, printElement);

	std::cout << "String array:" << std::endl;
	iter(strArray, 3, printElement);

	std::cout << "Const int array:" << std::endl;
    iter(constArray, 3, printConstElement);

	return 0;
}
