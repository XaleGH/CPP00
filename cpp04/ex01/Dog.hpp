/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:43:11 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:10:19 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain* cerveau;
	
	public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog& operator=(const Dog &rhs);
	void makeSound() const;
	Brain* getBrain();
};

#endif