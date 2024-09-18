/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:57:41 by asaux             #+#    #+#             */
/*   Updated: 2024/09/18 16:17:04 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class	PhoneBook
{
	private:
		Contact contacts[8];
		int	index;
		int	total_contacts;
	public:
		PhoneBook();
		void	addContact();
		void	searchContact() const;
	private:
		std::string truncate(std::string str) const;
};

#endif