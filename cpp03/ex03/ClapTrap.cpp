/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:23:54 by asaux             #+#    #+#             */
/*   Updated: 2024/11/07 18:17:12 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("NONE"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap is born !" << std::endl;
}

ClapTrap::ClapTrap (const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " is born !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "ClapTrap " << _name << " is destroyed !" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << "assignment constructor called" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& c)
{
	os << c.getName() << "'s energy point is " << c.getEnergyPoints() << std::endl;
	os << c.getName() << "'s attack damage is " << c.getAttackDamage() << std::endl;
	os << c.getName() << "'s hit point is " << c.getHitPoints() << std::endl;
	return os;
}

void ClapTrap::attack (const std::string& target) 
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage." << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy points or no hit points for attacks" << std::endl;
}

void ClapTrap::takeDamage (unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints = (_hitPoints < amount) ? 0 : _hitPoints - amount;
		std::cout << "ClapTrap " << _name << " take " << amount << " points of damage !" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't take more damage !" << std::endl;
	}
}

void ClapTrap::beRepaired (unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " repairs itself, restoring " << amount << " life points !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy to repair himself !" << std::endl;
}

std::string ClapTrap::getName() const
{
	return _name;
}

int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}
