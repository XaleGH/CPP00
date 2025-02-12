/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:53:01 by asaux             #+#    #+#             */
/*   Updated: 2025/02/12 14:06:56 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_attackDamage = 30;
	_energyPoints = 100;
	_hitPoints = 100;
	_name = "NONE";
	std::cout << "FragTrap has been invocated !" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << name << " has been invocated !" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	*this = src;
	std::cout << "Frag copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been revoked !" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const FragTrap& s)
{
	os << static_cast<const ClapTrap&>(s);
	return os;
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "FragTrap " << _name << " hurls a grenade at " << target << ", causing " << _attackDamage << " points of damage." << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "FragTrap " << _name << " lacks the energy to attack." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}