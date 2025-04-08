/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:54:08 by asaux             #+#    #+#             */
/*   Updated: 2025/04/07 15:00:47 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern( const Intern & src )
{
	*this = src;
}

Intern::~Intern(){}

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*formCreators[3])(std::string target) = {ShrubberyCreationForm::create, RobotomyRequestForm::create, PresidentialPardonForm::create};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return formCreators[i](target);
		}
	}
	throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}