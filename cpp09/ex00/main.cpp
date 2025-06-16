/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:46:07 by asaux             #+#    #+#             */
/*   Updated: 2025/05/28 11:36:55 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

bool isNumber(const std::string& s)
{
	if (s.empty())
		return false;
	char* end;
	double d = std::strtod(s.c_str(), &end);
	(void) d;
	return *end == '\0';
}

bool isTooBig(const std::string& s)
{
	double d = std::strtod(s.c_str(), NULL);
	return d > 1000.0;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	if (!btc.loadDatabase("data.csv"))
	{
		std::cerr << "Error: could not load database." << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string value = line.substr(sep + 1);

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		value.erase(0, value.find_first_not_of(" \t"));
		value.erase(value.find_last_not_of(" \t") + 1);

		if (!btc.isDateValid(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (!isNumber(value))
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (isTooBig(value))
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double amount = std::strtod(value.c_str(), NULL);
		if (amount < 0.0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		try {
			float rate = btc.getRateForDate(date);
			std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}
