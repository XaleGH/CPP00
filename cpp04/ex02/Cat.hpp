/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:34:07 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:25:44 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
	Brain *cerveau;
	
	public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat& operator=(const Cat &rhs);
	void makeSound() const;
	Brain *getBrain();
};

#endif