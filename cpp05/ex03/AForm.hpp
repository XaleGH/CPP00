/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:05:27 by asaux             #+#    #+#             */
/*   Updated: 2025/04/04 15:49:41 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		AForm(std::string const name, int GradeToSign, int GradeToExecute);
		AForm(const AForm &copy);
		virtual ~AForm();

		AForm& operator=(const AForm &rhs);

		const std::string& getName() const;
		bool getSigned() const;
		void setSigned(bool sign);
		void beSigned(Bureaucrat& bureaucrat);
		int getGradeToSign() const;
		int getGradeToExecute() const;
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class FormAlreadySignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
};
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif