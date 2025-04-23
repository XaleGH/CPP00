/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:07:04 by asaux             #+#    #+#             */
/*   Updated: 2025/04/23 11:39:04 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int main (void)
{
	srand(time(NULL));
	Base base1;
	Base* random1 = base1.generate();
	Base* random2 = base1.generate();
	Base& base2 = *random2;
	
	std::cout << "---------------Normal Test-------------------\n\n";
	base1.identify(random1);
	base1.identify(random2);
	base1.identify(base2);

	std::cout << "\n---------------Error Test--------------------\n\n";
	Base err;
	Base *random3 = NULL;
	Base& base3 = *random3;
	std::cout << "[Case 1] identify an empty Base with pointer\n";
	err.identify(random3);
	std::cout << "[Case 2] identify an empty Base with ref\n";
	err.identify(base3);

	delete random1;
	delete random2;
	return 0;
}