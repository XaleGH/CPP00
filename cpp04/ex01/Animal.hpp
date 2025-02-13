/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:01:17 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:00:22 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
	std::string _type;

	public:
	Animal();
	Animal(Animal const& src);
	virtual ~Animal();

	Animal& operator=(const Animal &rhs);
	virtual void makeSound() const;
	const std::string&	getType() const;
};

#endif