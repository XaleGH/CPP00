/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:16:29 by asaux             #+#    #+#             */
/*   Updated: 2025/04/12 14:23:42 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _id(0), _name("Default")
{
	std::cout << "Default constructor called" << std::endl;
}

Data::Data(const std::string& name, int id) : _id(id), _name(name)
{
	std::cout << "Param constructor called" << std::endl;
}

Data::Data(const Data& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Data& Data::operator=(const Data& other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		_id = other._id;
		_name = other._name;
	}
	return *this;
}

Data::~Data()
{
	std::cout << "Destructor called" << std::endl;
}

int Data::getId() const
{
	return _id;
}

const std::string& Data::getName() const
{
	return _name;
}
