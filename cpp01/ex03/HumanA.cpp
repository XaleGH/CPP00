/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:23:07 by asaux             #+#    #+#             */
/*   Updated: 2024/09/26 12:21:26 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}