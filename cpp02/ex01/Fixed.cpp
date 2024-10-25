/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:35:07 by asaux             #+#    #+#             */
/*   Updated: 2024/10/25 15:27:36 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(num << _fractionalBits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(num * (1 << _fractionalBits)));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_value) / 256);
}

int Fixed::toInt() const
{
	return (_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}