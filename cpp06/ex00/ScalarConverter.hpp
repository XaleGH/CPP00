/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:37:17 by asaux             #+#    #+#             */
/*   Updated: 2025/04/10 15:59:16 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <climits>
# include <cmath>

class ScalarConverter
{

	private:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		ScalarConverter &		operator=( ScalarConverter const & rhs );

	public:

		~ScalarConverter();
		
		static void			convert( std::string const & str );
		
		class NonDisplayable : public std::runtime_error
		{
			public:
				NonDisplayable();
		};

		class Impossible : public std::runtime_error
		{
			public:
				Impossible();
		};

};

#endif