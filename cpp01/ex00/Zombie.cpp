/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:01:33 by asaux             #+#    #+#             */
/*   Updated: 2024/09/23 17:39:24 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Zombie " << _name << " is created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " is destroyed." << std::endl;
}

void Zombie::annonce() const
{
	std::cout << "Zombie " << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}