/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:54:06 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 14:40:23 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal( WrongAnimal const & src );
	~WrongAnimal();

	WrongAnimal &		operator=( WrongAnimal const & rhs );
	void 	makeSound() const;
	std::string 	getType() const;

	protected:
	std::string _type;

};

#endif