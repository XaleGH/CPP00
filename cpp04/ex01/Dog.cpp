/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:45:52 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:14:20 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), cerveau(new Brain())
{
	_type = "Dog";
	std::cout << "A Dog is created" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy), cerveau(new Brain(*copy.cerveau))
{
	this->_type = copy.getType();
	std::cout << "Dog copy constructor is created" << std::endl;
}

Dog::~Dog()
{
	delete cerveau;
	std::cout << "Dog is destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		delete cerveau;
		cerveau = new Brain(*rhs.cerveau);
		std::cout << "Dog assignment operator is called" << std::endl;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woofs Woofs !" << std::endl;
}

Brain* Dog::getBrain()
{
	return cerveau;
}