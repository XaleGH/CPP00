/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:54:49 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 15:29:38 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main()
{
	//create an array of animal and assign dog and cat classes
	std::cout << "---------Test : Creating an array of animal and assign dog and cat classes----------" << std::endl;
	Animal* animal[10];
	
	for (int i = 0; i < 5; i++)
	{
		animal[i] = new Dog();
		animal[i + 5] = new Cat();
	}

	std::cout << "---Test : Deleting the array of animal---" << std::endl;
	for (int j = 0; j < 10; j++)
		delete animal[j];


	Dog shiva;

	std::cout << "The Second idea of shiva in his brain is " << shiva.getBrain()->ideas[1] << std::endl;
	shiva.getBrain()->ideas[1] = "I changed my mind";
	Dog chiwawa = shiva;
	std::cout << "Chiwawa who is a copy of Shiva has his second idea : " << chiwawa.getBrain()->ideas[1] << std::endl;
	
	return 0;
}