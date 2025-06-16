/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:06:27 by asaux             #+#    #+#             */
/*   Updated: 2025/05/05 11:26:18 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 2);

	try {
		std::vector<int>::iterator found = easyfind(vec, 6);
		std::cout << "Found: " << *found << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		easyfind(vec, 7);
	} catch (std::exception& e) {
		std::cerr << "Not found: " << e.what() << std::endl;
	}

	std::list<int> lst;
	for (int i = 1; i <= 5; ++i)
		lst.push_back(i * 10);

	try {
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "List found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cerr << "List not found: " << e.what() << std::endl;
	}

	return 0;
}
