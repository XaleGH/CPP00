/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:21:44 by asaux             #+#    #+#             */
/*   Updated: 2024/11/15 02:04:23 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
	
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(DiamondTrap const& src);
		~DiamondTrap();

		DiamondTrap& operator=(DiamondTrap const & rhs);
		void attack(const std::string& name);
		void whoAmI();
		std::string getName() const;
};

std::ostream& operator<<(std::ostream & os, DiamondTrap const & i);

#endif