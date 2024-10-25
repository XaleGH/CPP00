/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:35:05 by asaux             #+#    #+#             */
/*   Updated: 2024/10/25 13:46:48 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int num);
		Fixed(const float num);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
		int toInt() const;
		float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& other);

#endif