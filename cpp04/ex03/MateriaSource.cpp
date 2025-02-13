/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:37:43 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 16:05:16 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		learnedList[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destoying learned Materias\n";
	for (int i = 0; i < 4; i++)
	{
		if (learnedList[i])
			delete learnedList[i];
	}
}

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 4; i++)
		{
			if (learnedList[i])
				delete learnedList[i];
			learnedList[i] = rhs.learnedList[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!learnedList[i])
		{
			learnedList[i] = m;
			std::cout << "Learned a new Materia!\n";
			return;
		}
		if (i == 3)
		{
			delete m;
			std::cout << "Can't learn another Materia anymore\n";
		}
	}
	

}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4 && learnedList[i]; i++)
	{
		if (learnedList[i]->getType() == type)
			return (learnedList[i]->clone());
	}
	return 0;
}