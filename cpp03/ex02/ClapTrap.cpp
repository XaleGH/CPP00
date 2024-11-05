/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:23:54 by asaux             #+#    #+#             */
/*   Updated: 2024/11/05 12:48:58 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap (const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " is born !" << std::endl;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "ClapTrap " << name << " is destroyed !" << std::endl;
}

void ClapTrap::attack (const std::string& target) 
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage." << std::endl;
		energyPoints--;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy points or no hit points for attacks" << std::endl;
}

void ClapTrap::takeDamage (unsigned int amount)
{
	if (hitPoints > 0)
	{
		hitPoints = (hitPoints < amount) ? 0 : hitPoints - amount;
		std::cout << "ClapTrap " << name << " take " << amount << " points of damage !" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " can't take more damage !" << std::endl;
	}
}

void ClapTrap::beRepaired (unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " repairs itself, restoring " << amount << " life points !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy to repair himself !" << std::endl;
}