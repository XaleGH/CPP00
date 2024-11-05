/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:17 by asaux             #+#    #+#             */
/*   Updated: 2024/11/05 17:02:28 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap ft("FT-001");

	ft.attack("Enemy Target");
	ft.takeDamage(20);
	ft.beRepaired(15);
	ft.highFivesGuys();

	return 0;
}