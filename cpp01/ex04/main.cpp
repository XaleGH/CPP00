/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:48:26 by asaux             #+#    #+#             */
/*   Updated: 2024/10/08 17:20:43 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceString(std::string subject, const std::string& search, const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos)
	{
		 subject.erase(pos, search.length());
		 subject.insert(pos, replace);
		 pos += replace.length();
	}
	return subject;
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string new_filename = filename + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Search string cannot be empty." << std::endl;
		return 1;
	}

	std::ifstream fileIn(filename.c_str());
	if (!fileIn)
	{
		std::cerr << "Could not open file: " << filename << std::endl;
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(fileIn)), std::istreambuf_iterator<char>());
	fileIn.close();

	content = replaceString(content, s1, s2);

	std::ofstream fileOut(new_filename.c_str());
	if (!fileOut)
	{
		std::cerr << "Could not create output file." << std::endl;
		return 1;
	}

	fileOut << content;
	fileOut.close();

	return (0);
}