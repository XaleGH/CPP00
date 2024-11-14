/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:17 by asaux             #+#    #+#             */
/*   Updated: 2024/11/07 18:16:18 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("R2-D2");
	std::cout << clap;
	clap.takeDamage(5);
	clap.attack("target");
	std::cout << clap;
	clap.beRepaired(3);
	std::cout << clap;
	return 0;
}