/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:54:49 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:31:58 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	//AAnimal test; ->non-instantiable(abstract class)
	//create an array of animal and assign dog and cat classes
	AAnimal *animal[10];
	std::cout << "---------Test : Creating an array of animal and assign dog and cat classes----------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Dog();
		animal[i + 5] = new Cat();
	}
	std::cout << "---Test : Deleting the array of animal---" << std::endl;
	for (int j = 0; j < 10; j++)
		delete animal[j];
	std::cout << "-----Test : Creating Shiva-------\n";
	Dog shiva;    
	std::cout << "Shiva thinks that " << shiva.getBrain()->ideas[1] << std::endl;
	shiva.getBrain()->ideas[1] = "I want to go walk without leash";
	shiva.getBrain()->ideas[2] = "I want to have a treat";
	shiva.getBrain()->ideas[3] = "I want to play";
	std::cout << "-------Test: Deep Copy Shiva to Chiwawa-------\n";
	Dog chiwawa(shiva);
	std::cout << "--------Does Chiwawa think the same as Shiva?---------\n";
	std::cout << chiwawa.getBrain()->ideas[1] << std::endl;
	std::cout << chiwawa.getBrain()->ideas[2] << std::endl;
	std::cout << chiwawa.getBrain()->ideas[3] << std::endl;
	return 0;
}