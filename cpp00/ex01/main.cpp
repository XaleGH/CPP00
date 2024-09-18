/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:38:18 by asaux             #+#    #+#             */
/*   Updated: 2024/09/18 17:10:17 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook phonebook;
	std::string command;

	while(1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, command);
		std::cout << "TEST : " << command << std::endl;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, EXIT." << std::endl;
	}
	return (0);
}