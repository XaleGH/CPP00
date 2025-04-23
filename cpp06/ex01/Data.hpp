/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:16:14 by asaux             #+#    #+#             */
/*   Updated: 2025/04/12 14:23:11 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	private:
		int			_id;
		std::string	_name;

	public:
		Data();
		Data(const std::string& name, int id);
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();

		int getId() const;
		const std::string& getName() const;
};

#endif
