/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:21:19 by asaux             #+#    #+#             */
/*   Updated: 2024/11/15 02:10:46 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap is constructed !" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = ScavTrap::energyPoints;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << "DiamondTrap " << this->name << " is constructed !" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = ScavTrap::energyPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src)
{
	*this = src;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiammondTrap " << this->name << " is destroyed !" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if ( this != &rhs )
	{
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
		this->_name = rhs._name;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, DiamondTrap const& c)
{
	os << c.getName() << "'s energy point is " << c.getEnergyPoints() << std::endl;
	os << c.getName() << "'s attack damage is " << c.getAttackDamage() << std::endl;
	os << c.getName() << "'s hit point is " << c.getHitPoints() << std::endl;
	return os;
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

std::string DiamondTrap::getName() const
{
	return _name;
}