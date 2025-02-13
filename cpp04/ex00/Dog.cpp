/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:45:52 by asaux             #+#    #+#             */
/*   Updated: 2025/02/12 17:51:08 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog constructor is created" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	*this = copy;
	std::cout << "Dog copy constructor is created" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog is destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
		Dog::operator=(rhs);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woofs Woofs !" << std::endl;
}