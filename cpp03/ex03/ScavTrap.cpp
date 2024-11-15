/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:27:14 by asaux             #+#    #+#             */
/*   Updated: 2024/11/14 15:25:19 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_attackDamage = 20;
	_energyPoints = 50;
	_hitPoints = 100;
	_name = "NONE";
	std::cout << "ScavTrap has been summoned !" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " has been summoned !" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	*this = src;
	std::cout << "Scav copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed !" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& s)
{
	os << static_cast<const ClapTrap&>(s);
	return os;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " hits " << target << ", causing " << _attackDamage << " points of damage." << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << _name << " has no energy points or no hit points for attacks" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode." << std::endl;
}