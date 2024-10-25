/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:35:07 by asaux             #+#    #+#             */
/*   Updated: 2024/10/25 17:31:50 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed& other) : _value(other.getRawBits()) {}

Fixed::Fixed(const int num) : _value(num << _fractionalBits) {}

Fixed::Fixed(const float num) : _value(roundf(num * (1 << _fractionalBits))) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

bool Fixed::operator>(const Fixed& rhs) const {return (_value > rhs._value);}
bool Fixed::operator<(const Fixed& rhs) const {return (_value < rhs._value);}
bool Fixed::operator>=(const Fixed& rhs) const {return (_value >= rhs._value);}
bool Fixed::operator<=(const Fixed& rhs) const {return (_value <= rhs._value);}
bool Fixed::operator==(const Fixed& rhs) const {return (_value == rhs._value);}
bool Fixed::operator!=(const Fixed& rhs) const {return (_value != rhs._value);}

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

Fixed Fixed::operator+(const Fixed& rhs) const { return Fixed(this->toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(const Fixed& rhs) const { return Fixed(this->toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(const Fixed& rhs) const { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed& rhs) const { return Fixed(this->toFloat() / rhs.toFloat()); }

Fixed& Fixed::operator++() { _value++; return *this; }
Fixed Fixed::operator++(int) { Fixed temp(*this); ++(*this); return temp; }
Fixed& Fixed::operator--() { _value--; return *this; }
Fixed Fixed::operator--(int) { Fixed temp(*this); --(*this); return temp; }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}