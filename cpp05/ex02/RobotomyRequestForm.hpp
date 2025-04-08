/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:41:48 by asaux             #+#    #+#             */
/*   Updated: 2025/04/07 09:48:38 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		
	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void	setTarget(std::string target);
		const	std::string & getTarget() const;
		void	execute(Bureaucrat const & executor) const;
		
		class TargetErrorException : public std::exception
		{
			virtual const char* what() const throw();
		};	

};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif