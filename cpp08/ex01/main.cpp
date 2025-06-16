/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:25:10 by asaux             #+#    #+#             */
/*   Updated: 2025/05/06 15:03:50 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	{
		Span big(10000);
		std::vector<int> batch;
		for (int i = 0; i < 10000; ++i)
			batch.push_back(rand());

		big.addRange(batch.begin(), batch.end());

		std::cout << "Shortest: " << big.shortestSpan() << std::endl;
		std::cout << "Longest: " << big.longestSpan() << std::endl;
	}

	return 0;
}
