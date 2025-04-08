/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:41:51 by asaux             #+#    #+#             */
/*   Updated: 2025/04/07 11:12:37 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {};

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src)
{
	*this = src;
}
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (target.empty())
	{
		throw RobotomyRequestForm::TargetErrorException();
	}
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
	(void)executor;
	srand(time(NULL));
	int i = rand() % 2;

	std::cout << "DRRRRR---------" << std::endl;
	std::cout << "DRRRRR---------" << std::endl;
	std::cout << "DRRRRR---------" << std::endl;
	if (i)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
}

const char* RobotomyRequestForm::TargetErrorException::what() const throw()
{
	return "Target is empty.";
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "Name : " << i.getName() << std::endl;
	o << "Target : " << i.getTarget() << std::endl;
	o << "Signed : " << i.getSigned() << std::endl;
	o << "Minimum grade to sign : " << i.getGradeToSign() << std::endl;
	o << "Minimum grade to execute : " << i.getGradeToExecute() << std::endl;
	return o;
}

const std::string&	RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}

void	RobotomyRequestForm::setTarget( std::string target )
{
	this->_target = target;
}
