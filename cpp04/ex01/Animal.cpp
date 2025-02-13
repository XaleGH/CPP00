/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:01:05 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 14:59:00 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "";
	std::cout << "Animal is created" << std::endl;
}

Animal::Animal(const Animal& src)
{
	this->_type = src.getType();
	std::cout << "Animal copy constructor is created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal is destroyed" << std::endl;
}

Animal& Animal::operator=(Animal const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	std::cout << "Animal assigment operator is called" << std::endl;
	return *this;
}

const std::string& Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "-----------" << std::endl;
}
