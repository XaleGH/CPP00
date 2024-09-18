/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:38:27 by asaux             #+#    #+#             */
/*   Updated: 2024/09/18 15:17:45 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(std::string fname)
{
	first_name = fname;
}

void Contact::setLastName(std::string lname)
{
	last_name = lname;
}

void Contact::setNickname(std::string nname)
{
	nickname = nname;
}

void Contact::setPhoneNumber(std::string pnumber)
{
	phone_number = pnumber;
}

void Contact::setDarkestSecret(std::string secret)
{
	darkest_secret = secret;
}

std::string Contact::getFirstName() const
{
	return first_name;
}

std::string Contact::getLastName() const
{
	return last_name;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phone_number;
}

std::string Contact::getDarkestSecret() const
{
	return darkest_secret;
}