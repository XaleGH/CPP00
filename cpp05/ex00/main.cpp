/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:39:51 by asaux             #+#    #+#             */
/*   Updated: 2025/03/28 15:34:25 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	std::cout << "Test 0: create a bureaucrat with invalid grade" << std::endl;
	try
	{
		Bureaucrat Toto("Toto", 160);
	}
	catch(const std::exception& err)
	{
		std::cerr << "Toto" << err.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	Bureaucrat bill("Bill", 150);
	Bureaucrat bob("Bob", 1);
	Bureaucrat john("John", 75);
	
	std::cout << bill << std::endl;
	std::cout << bob << std::endl;
	std::cout << john << std::endl;

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Test 1: decrease 1 grade down of Bill" << std::endl;
	try
	{
		bill.decrementGrade();
		std::cout << bill.getGrade() << std::endl;

	}
	catch(const std::exception& err)
	{
		std::cerr << bill.getName() + err.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Test 2: increase 1 grade up of Bob" << std::endl;
	try
	{
		bob.incrementGrade();
		std::cout << bob.getGrade() << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << bob.getName() << err.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Test 3: increase 1 grade up of John" << std::endl;
	try
	{
		john.incrementGrade();
		std::cout << "John's upgraded to " << john.getGrade() << std::endl; 
	}
	catch(const std::exception& err)
	{
		std::cerr << john.getName() + err.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Test 4: decrease 1 grade up of Bob" << std::endl;
	try
	{
		bob.decrementGrade();
		std::cout << "Bob's downgraded to " << bob.getGrade() << std::endl; 
	}
	catch(const std::exception& err)
	{
		std::cerr << bob.getName() + err.what() << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Test 5: increase 1 grade up of Bill" << std::endl;
	try
	{
		bill.incrementGrade();
		std::cout << "Bill's upgraded to " << bill.getGrade() << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << bill.getName() + err.what() << std::endl;
	}
	return 0;
}