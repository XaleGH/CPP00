/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:53:16 by asaux             #+#    #+#             */
/*   Updated: 2024/11/14 15:49:40 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& copy);
		~FragTrap();
		
		FragTrap& operator=(FragTrap const& rhs);
		
		void attack(const std::string& target);
		void highFivesGuys();
};

std::ostream& operator<<(std::ostream& os, const FragTrap& s);

#endif