/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:38:18 by asaux             #+#    #+#             */
/*   Updated: 2024/09/23 11:09:37 by asaux            ###   ########.fr       */
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
		if (std::cin.fail())
		{
			std::cout << std::endl;
			std::cout << "Error. Relaunch phonebook" << std::endl;
			return (1);
		}
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