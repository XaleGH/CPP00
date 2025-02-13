/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:35:33 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 16:00:30 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "A Character is created\n";
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character(std::string _name)
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	name = _name;
	std::cout << "Character " << name << " is created\n";
}

Character::Character( const Character & src )
{
	*this = src;
}

Character::~Character()
{
	std::cout << "Destroying slots of " << name <<"...." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slots[i])
		{
			std::cout << "Successfully deleting " << slots[i]->getType() << std::endl;
			delete slots[i];
			slots[i] = NULL;
		}
	}
}

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		for (int i = 0; i < 4 && slots[i]; i++)
		{
			delete slots[i];
			slots[i] = NULL;
			if (rhs.slots[i])
				this->slots[i] = rhs.slots[i]->clone();
		}
	}
	return *this;
}

void	Character::equip(AMateria *m)
{
	int i = 0;
	if (m == 0)
	{
		std::cout << "No Materia found to equip\n";
		return;
	}
	while (slots[i] && i < 4)
		i++;
	if (!slots[i])
	{
		std::cout << this->getName() << " has equipped " << m->getType() << std::endl;
		slots[i] = m;
	}
	else
		std::cout << "Slot is already full\n";
}
void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Out of the index range( 0 ~ 3 )\n";
	else if (slots[idx] == NULL)
		std::cout << "There's nothing to be unequiped\n";
	else
	{
		std::cout << "Succesfully unequipped " << slots[idx]->getType() << std::endl;
		slots[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Out of the index range( 0 ~ 3 )\n";
	else if (slots[idx])
		slots[idx]->use(target);
	else
		std::cout << "the slot is empty\n";
}

std::string const& Character::getName() const
{
	return name;
}