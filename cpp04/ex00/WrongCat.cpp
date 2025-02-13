/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:54:33 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 14:47:46 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat constructor is created" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src ) : WrongAnimal(src)
{
	*this = src;
	std::cout << "WrongCat copy constructor is created" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destroyed" << std::endl;
}

WrongCat &	WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
		WrongCat::operator=(rhs);
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "MMMMMMMMeow Meow!!!!!!!!!!" << std::endl;
}