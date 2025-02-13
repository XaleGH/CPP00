/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:03:31 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:08:50 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "N/A";
	std::cout << "Brain is created" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain copy constructor is called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain is destroyed" << std::endl;
}

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}