/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:17 by asaux             #+#    #+#             */
/*   Updated: 2024/11/05 18:09:02 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("UltimateDiamond");

	dt.attack("Target");
	dt.takeDamage(30);
	dt.beRepaired(50);
	dt.whoAmI();

	return 0;
}