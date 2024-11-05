/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:17 by asaux             #+#    #+#             */
/*   Updated: 2024/11/05 16:40:30 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("Guardian");
	scav.attack("Intruder");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	return 0;
}