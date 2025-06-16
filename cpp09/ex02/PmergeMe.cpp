/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:21:23 by asaux             #+#    #+#             */
/*   Updated: 2025/06/16 10:44:30 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib> // pour std::atoi

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositiveNumber(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i)
		if (!isdigit(str[i]))
			return false;
	return true;
}

void PmergeMe::parseInput(int argc, char** argv)
{
	if (argc < 2)
		throw std::invalid_argument("Error: Need at least one positive number.");
	checkAndFillContainers(argc, argv);
}

void PmergeMe::checkAndFillContainers(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (!isPositiveNumber(arg))
			throw std::invalid_argument("Error: Invalid input => " + arg);
		int val = std::atoi(argv[i]);
		vec.push_back(val);
		deq.push_back(val);
	}
}

// ------------------------
// Algorithme Ford-Johnson
// ------------------------

template<typename T>
T PmergeMe::mergeInsertSort(const T& input)
{
	if (input.size() <= 1)
		return input;

	T mainChain;
	T pendingChain;

	// Étape 1 : Créer des paires et trier les paires
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
		{
			mainChain.push_back(input[i + 1]);
			pendingChain.push_back(input[i]);
		}
		else
		{
			mainChain.push_back(input[i]);
			pendingChain.push_back(input[i + 1]);
		}
	}

	// Si taille impaire, on garde le dernier élément à insérer plus tard
	if (input.size() % 2 != 0)
		pendingChain.push_back(input.back());

	// Étape 2 : Trier mainChain récursivement
	mainChain = mergeInsertSort(mainChain);

	// Étape 3 : Insérer les éléments de pendingChain dans mainChain
	for (size_t i = 0; i < pendingChain.size(); ++i)
		binaryInsert(mainChain, pendingChain[i]);

	return mainChain;
}

template<typename T>
void PmergeMe::binaryInsert(T& sorted, typename T::value_type value)
{
	typename T::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int>& input)
{
	return mergeInsertSort(input);
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int>& input)
{
	return mergeInsertSort(input);
}

// ------------------------
// Affichage des conteneurs
// ------------------------

template<typename T>
void PmergeMe::printContainer(const std::string& label, const T& container)
{
	std::cout << label;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// ------------------------
// Lancement du traitement
// ------------------------

void PmergeMe::process()
{
	
	printContainer("Before: ", vec);

	clock_t startVec = clock();
	std::vector<int> sortedVec = fordJohnsonVector(vec);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	std::deque<int> sortedDeq = fordJohnsonDeque(deq);
	clock_t endDeq = clock();

	printContainer("After:  ", sortedVec);

	double durationVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
	double durationDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process " << vec.size() << " elements with std::vector: "
			  << durationVec << " us" << std::endl;

	std::cout << "Time to process " << deq.size() << " elements with std::deque: "
			  << durationDeq << " us" << std::endl;
}

// Spécialisations template pour éviter linker error
template std::vector<int> PmergeMe::mergeInsertSort(const std::vector<int>& input);
template std::deque<int> PmergeMe::mergeInsertSort(const std::deque<int>& input);
template void PmergeMe::binaryInsert(std::vector<int>& sorted, int value);
template void PmergeMe::binaryInsert(std::deque<int>& sorted, int value);
template void PmergeMe::printContainer(const std::string& label, const std::vector<int>&);
template void PmergeMe::printContainer(const std::string& label, const std::deque<int>&);
