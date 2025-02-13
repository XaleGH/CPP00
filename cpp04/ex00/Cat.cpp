/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:36:46 by asaux             #+#    #+#             */
/*   Updated: 2025/02/12 17:42:54 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat constructor is created" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	*this = src;
	std::cout << "Cat copy constructor is created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat is destroyed" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}