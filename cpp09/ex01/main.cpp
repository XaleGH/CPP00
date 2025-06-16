/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:50:27 by asaux             #+#    #+#             */
/*   Updated: 2025/06/11 14:47:04 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		RPN calculator;
		calculator.evaluateExpression(argv[1]);
		std::cout << calculator.getResult() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return 0;
}
