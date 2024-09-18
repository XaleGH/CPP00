/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:57:43 by asaux             #+#    #+#             */
/*   Updated: 2024/09/18 17:13:02 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : index(0), total_contacts(0) {}

void	PhoneBook::addContact()
{
	Contact new_contact;
	std::string input;
	
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	new_contact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	new_contact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	new_contact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	new_contact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	new_contact.setDarkestSecret(input);

	contacts[index] = new_contact;
	index = (index + 1) % 8;
	if (total_contacts < 8)
		total_contacts++;
}

void	PhoneBook::searchContact() const
{
	if (total_contacts == 0)
	{
		std::cout << "No Contacts available." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < total_contacts; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
				  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}
	int indx;
	std::cout << "Enter intex to display: ";
	std::cin >> indx;
	if (std::cin.fail() || indx < 1 || indx > total_contacts)
	{
		std::cout << "Invalid index." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	std::cout << "First name : " << contacts[indx - 1].getFirstName() << std::endl;
	std::cout << "Last name : " << contacts[indx - 1].getLastName() << std::endl;
	std::cout << "Nickname : " << contacts[indx - 1].getNickname() << std::endl;
	std::cout << "Phone number : " << contacts[indx - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contacts[indx - 1].getDarkestSecret() << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string PhoneBook::truncate(std::string str) const 
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}