/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:38:08 by asaux             #+#    #+#             */
/*   Updated: 2025/02/13 16:04:16 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

#include <vector>

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	std::cout << "---------Try learning 5 Materias----- \n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure()); // no more space to learn

	ICharacter* me = new Character("me");

	AMateria* tmp;
	std::vector<AMateria*> unequippedMateria;
	std::cout << "---------Try equiping Materias----- \n";
	tmp = src->createMateria("ice");
	me->equip(tmp);
	unequippedMateria.push_back(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	unequippedMateria.push_back(tmp);
	tmp = src->createMateria("stone");
	me->equip(tmp);
   
	ICharacter* bob = new Character("bob");
	std::cout << "---------Try using Materias----- \n";
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "---------Try invalid Materias----- \n";
	bob->use(2, *me); //bob has no materias
	me->use(5, *bob); //index out of range
	std::cout << "---------Try unequipping Materias----- \n";
	me->unequip(0);
	me->unequip(1);
	me->unequip(4);
	for (size_t i = 0; i < unequippedMateria.size(); i++) //free unequippted materias
		delete unequippedMateria[i];
	std::cout << "------Destructors called---------" << std::endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}