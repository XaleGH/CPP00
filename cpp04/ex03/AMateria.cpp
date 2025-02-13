/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:35:04 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:40:36 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria constructor is called\n";
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
}

AMateria::AMateria(std::string const &_type)
{
	type = _type;
} 

AMateria::~AMateria()
{
	std::cout << "Destructor of AMateria is called\n";
}

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
		this->type = rhs.getType();
	return *this;
}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use function is calling " << target.getName() << std::endl;
}