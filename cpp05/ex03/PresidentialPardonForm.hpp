/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:39:33 by asaux             #+#    #+#             */
/*   Updated: 2025/04/07 15:12:50 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=( PresidentialPardonForm const & rhs );
		
		void setTarget(std::string target);
		const std::string& getTarget() const;
		
		void execute(Bureaucrat const & executor) const;
		static AForm* create(std::string target);
		
		class TargetErrorException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif