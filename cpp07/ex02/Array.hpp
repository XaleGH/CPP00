/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:41:14 by asaux             #+#    #+#             */
/*   Updated: 2025/04/30 15:03:18 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <exception>
# include <iostream>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int n) : _array(new T[n]), _size(n) {}

		Array(const Array& other) : _array(NULL), _size(0)
		{
			*this = other;
		}

		~Array()
		{
			delete[] _array;
		}

		Array& operator=(const Array& other)
		{
			if (this != &other) {
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_array[i] = other._array[i];
			}
			return *this;
		}

		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}

		unsigned int size() const
		{
			return _size;
		}
};

#endif
