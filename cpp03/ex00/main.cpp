/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:17 by asaux             #+#    #+#             */
/*   Updated: 2024/11/05 15:32:57 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("R2-D2");
	
	claptrap.attack("Enemy Bot");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);

	claptrap.attack("Enemy Bot");
	claptrap.takeDamage(8);
	claptrap.beRepaired(5);

	return 0;
}