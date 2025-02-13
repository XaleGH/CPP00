/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:36:46 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:26:19 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(), cerveau(new Brain())
{
	_type = "Cat";
	std::cout << "A Cat is created" << std::endl;
}

Cat::Cat(const Cat& src) : AAnimal(src), cerveau(new Brain(*src.cerveau))
{
	this->_type = src.getType();
	std::cout << "Cat copy constructor is created" << std::endl;
}

Cat::~Cat()
{
	delete cerveau;
	std::cout << "Cat is destroyed" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs)
{
	if (this != &rhs)
	{
		delete cerveau;
		cerveau = new Brain(*rhs.cerveau);
		std::cout << "Cat assignment is called" << std::endl;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain* Cat::getBrain()
{
	return cerveau;
}