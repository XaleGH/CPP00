/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:06:31 by asaux             #+#    #+#             */
/*   Updated: 2025/04/16 16:25:45 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* Base::generate(void)
{
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

// If dynamic_cast<A*>(p) fails, it return nullptr -> no try-catch needed
void Base::identify(Base* p)
{
	std::cout << "The result of the identification using Base pointer is ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

// If dynamic_cast<A&>(p) fails, it throws std::bad_cast.
void Base::identify(Base& p)
{
	std::cout << "The result of the identification using Base ref is ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception& e){
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
			return;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
				return;
			}
			catch(const std::exception& e)
			{

				std::cerr << "failed because of " << e.what() << '\n';
			}
		}
	}
}