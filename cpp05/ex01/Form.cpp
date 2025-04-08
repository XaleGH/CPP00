/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:05:15 by asaux             #+#    #+#             */
/*   Updated: 2025/04/03 17:07:02 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {};

Form::Form(std::string const name, int GradeToSign, int GradeToExecute) : _name(name), _isSigned(false), _gradeToSign(GradeToSign), _gradeToExecute(GradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
};

Form::Form(const Form &copy) : _name(copy.getName()), _isSigned(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	*this = copy;
};

Form::~Form() {};

std::string Form::getName() const
{
	return this->_name;
};

bool Form::getSigned() const
{
	return this->_isSigned;
};

void Form::setSigned(bool sign)
{
	this->_isSigned = sign;
};

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
};

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->setSigned(true);
	std::cout << bureaucrat.getName() << " has signed " << this->getName() << " form" << std::endl;
};

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
};

Form& Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getSigned();
	}
	return *this;
};

const char* Form::GradeTooHighException::what() const throw()
{
	return "its grade to sign this form is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "its grade to sign this form is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Name: " << form.getName() << std::endl;
	os << "Signed: " << form.getSigned() << std::endl;
	os << "Grade to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
};