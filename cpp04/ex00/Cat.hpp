/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:34:07 by asaux             #+#    #+#             */
/*   Updated: 2025/02/12 17:43:04 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat& operator=(const Cat &rhs);
	void makeSound() const;
};

#endif