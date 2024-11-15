/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:53:01 by asaux             #+#    #+#             */
/*   Updated: 2024/11/14 15:56:50 by asaux            ###   ########.fr       */
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
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " has been invocated !" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	*this = src;
	std::cout << "Frag copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been revoked !" << std::endl;
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
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "FragTrap " << name << " hurls a grenade at " << target << ", causing " << attackDamage << " points of damage." << std::endl;
		energyPoints--;
	}
	else
		std::cout << "FragTrap " << name << " lacks the energy to attack." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}