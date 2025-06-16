/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:45:28 by asaux             #+#    #+#             */
/*   Updated: 2025/05/27 10:55:32 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, valueStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
			continue;

		float value = static_cast<float>(std::atof(valueStr.c_str()));
		if (isDateValid(date))
			_rates[date] = value;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isDateValid(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int y = atoi(date.substr(0, 4).c_str());
	int m = atoi(date.substr(5, 2).c_str());
	int d = atoi(date.substr(8, 2).c_str());

	if (m < 1 || m > 12 || d < 1 || d > 31)
		return false;

	const int daysPerMonth[] = { 0, 31, 28, 31, 30, 31, 30,
								 31, 31, 30, 31, 30, 31 };
	int maxDay = daysPerMonth[m];
	if (m == 2 && isLeapYear(y))
		maxDay = 29;

	return d <= maxDay;
}

float BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);

	if (it == _rates.end() || it->first != date)
	{
		if (it == _rates.begin())
			throw std::runtime_error("Date too early.");
		--it;
	}
	return it->second;
}
