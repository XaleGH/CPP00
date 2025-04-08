/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:39:27 by asaux             #+#    #+#             */
/*   Updated: 2025/04/07 15:14:52 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src)
{
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (target.empty())
	{
		throw PresidentialPardonForm::TargetErrorException();
	}
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{	
	(void)executor;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::create(std::string target)
{
	return new PresidentialPardonForm(target);
};

const char* PresidentialPardonForm::TargetErrorException::what() const throw()
{
	return "Target is empty.";
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "Name : " << i.getName() << std::endl;
	o << "Target : " << i.getTarget() << std::endl;
	o << "Signed : " << i.getSigned() << std::endl;
	o << "Minimum grade to sign : " << i.getGradeToSign() << std::endl;
	o << "Minimum grade to execute : " << i.getGradeToExecute() << std::endl;
	return o;
}

void PresidentialPardonForm::setTarget(std::string target)
{
	this->_target = target;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return this->_target;
}