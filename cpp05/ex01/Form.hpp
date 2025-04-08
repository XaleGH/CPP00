/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:05:27 by asaux             #+#    #+#             */
/*   Updated: 2025/04/03 17:03:09 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(std::string const name, int GradeToSign, int GradeToExecute);
		Form(const Form &copy);
		~Form();

		Form& operator=(const Form &rhs);

		std::string getName() const;
		bool getSigned() const;
		void setSigned(bool sign);
		void beSigned(Bureaucrat& bureaucrat);
		int getGradeToSign() const;
		int getGradeToExecute() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
};
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif