/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:26:38 by asaux             #+#    #+#             */
/*   Updated: 2025/05/05 16:27:33 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			if (_numbers.size() + std::distance(begin, end) > _maxSize)
				throw std::runtime_error("Span is full");
			_numbers.insert(_numbers.end(), begin, end);
		}
};

#endif
