/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:01:17 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:24:52 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
	std::string _type;

	public:
	AAnimal();
	AAnimal(AAnimal const& src);
	virtual ~AAnimal();

	AAnimal& operator=(const AAnimal &rhs);
	virtual void makeSound() const = 0;
	const std::string&	getType() const;
};

#endif