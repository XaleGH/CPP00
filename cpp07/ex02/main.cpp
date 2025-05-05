/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:48:34 by asaux             #+#    #+#             */
/*   Updated: 2025/04/30 15:03:08 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	Array<int> copy = numbers;

	copy[0] = 999;
	std::cout << "After modification:" << std::endl;
	std::cout << "numbers[0] = " << numbers[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;

	try
	{
		std::cout << numbers[10] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
