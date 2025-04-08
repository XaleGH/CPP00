/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:05:15 by asaux             #+#    #+#             */
/*   Updated: 2025/04/04 15:22:37 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {};

AForm::AForm(std::string const name, int GradeToSign, int GradeToExecute) : _name(name), _isSigned(false), _gradeToSign(GradeToSign), _gradeToExecute(GradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
};

AForm::AForm(const AForm &copy) : _name(copy.getName()), _isSigned(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	*this = copy;
};

AForm::~AForm() {};

const std::string& AForm::getName() const
{
	return this->_name;
};

bool AForm::getSigned() const
{
	return this->_isSigned;
};

void AForm::setSigned(bool sign)
{
	this->_isSigned = sign;
};

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
};

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->setSigned(true);
	std::cout << bureaucrat.getName() << " has signed " << this->getName() << " form" << std::endl;
};

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
};

AForm& AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs.getSigned();
	}
	return *this;
};

const char* AForm::GradeTooHighException::what() const throw()
{
	return "its grade to sign this form is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "its grade to sign this form is too low";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Name: " << form.getName() << std::endl;
	os << "Signed: " << form.getSigned() << std::endl;
	os << "Grade to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
};