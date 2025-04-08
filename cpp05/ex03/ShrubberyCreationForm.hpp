/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:41:42 by asaux             #+#    #+#             */
/*   Updated: 2025/04/07 15:15:30 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
		
	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		void	setTarget(std::string target);
		const	std::string&	getTarget() const;
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		void	execute(Bureaucrat const & executor) const;
		static AForm* create(std::string target);

		class FileNotOpenedException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class TargetErrorException : public std::exception
		{
			virtual const char* what() const throw();
		};

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif