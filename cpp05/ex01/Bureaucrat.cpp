/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:39:42 by asaux             #+#    #+#             */
/*   Updated: 2025/04/03 16:33:26 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& c)
{
	os << c.getName() <<", bureaucrat grade " << c.getGrade();
	return os;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if ((this->_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if ((this->_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getSigned())
		std::cout << this->getName() << " cannot sign " << form.getName() << " because it's already signed !" << std::endl;
	else if (this->getGrade() > form.getGradeToSign())
		std::cout << this->getName() << " cannot sign " << form.getName() << " because his grade is too low !" << std::endl;
	else
		form.beSigned(*this);
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "'s grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "'s grade is too low";
}