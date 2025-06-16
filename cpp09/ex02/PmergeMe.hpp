/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:20:16 by asaux             #+#    #+#             */
/*   Updated: 2025/06/16 10:44:52 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iterator>
#include <stdexcept>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void parseInput(int argc, char** argv);
		void process();

	private:
		std::vector<int> vec;
		std::deque<int> deq;

		void checkAndFillContainers(int argc, char** argv);
		bool isPositiveNumber(const std::string& str);

		std::vector<int> fordJohnsonVector(const std::vector<int>& input);
		std::deque<int> fordJohnsonDeque(const std::deque<int>& input);

		template<typename T>
		void printContainer(const std::string& label, const T& container);

		// Fonctions internes Ford-Johnson
		template<typename T>
		T mergeInsertSort(const T& input);

		template<typename T>
		void binaryInsert(T& sorted, typename T::value_type value);
};

#endif
