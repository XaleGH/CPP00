/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:50:50 by asaux             #+#    #+#             */
/*   Updated: 2025/06/11 14:38:21 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <stdexcept>
# include <sstream>
# include <cstdlib>

class RPN
{
	private:
		std::stack<int> _stack;

		bool isOperator(char c) const;
		void applyOperator(char op);
		
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void evaluateExpression(const std::string& expr);
		int getResult() const;
};

#endif