/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:50:36 by asaux             #+#    #+#             */
/*   Updated: 2025/06/11 14:40:16 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::evaluateExpression(const std::string& expr)
{
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: not enough operands");
			applyOperator(token[0]);
		}
		else
		{
			char* end;
			long val = std::strtol(token.c_str(), &end, 10);
			if (*end != '\0' || val < 0 || val > 9)
				throw std::runtime_error("Error: invalid token");
			_stack.push(static_cast<int>(val));
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: malformed expression");
}

int RPN::getResult() const
{
	if (_stack.empty())
		throw std::runtime_error("Error: no result to return");
	return _stack.top();
}

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::applyOperator(char op)
{
	int rhs = _stack.top();
	_stack.pop();
	int lhs = _stack.top();
	_stack.pop();

	int result;

	switch (op)
	{
		case '+': result = lhs + rhs; break;
		case '-': result = lhs - rhs; break;
		case '*': result = lhs * rhs; break;
		case '/':
			if (rhs == 0)
				throw std::runtime_error("Error: division by zero");
			result = lhs / rhs;
			break;
		default:
			throw std::runtime_error("Error: unknown operator");
	}
	_stack.push(result);
}
