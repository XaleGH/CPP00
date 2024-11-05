/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:21:19 by asaux             #+#    #+#             */
/*   Updated: 2024/11/05 18:08:53 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << "DiamondTrap " << this->name << " is constructed !" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = ScavTrap::energyPoints;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiammondTrap " << this->name << " is destroyed !" << std::endl;
}

void DiamondTrap::attack (const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI ()
{
	std::cout << "DiamondTrap name : " << this->name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
}