/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:01:05 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:24:58 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	_type = "";
	std::cout << "AAnimal is created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	this->_type = src.getType();
	std::cout << "AAnimal copy constructor is created" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal is destroyed" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	std::cout << "AAnimal assigment operator is called" << std::endl;
	return *this;
}

const std::string& AAnimal::getType() const
{
	return _type;
}

/* void AAnimal::makeSound() const
{
	std::cout << "-----------" << std::endl;
} */
