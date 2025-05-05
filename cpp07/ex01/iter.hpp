/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:33:30 by asaux             #+#    #+#             */
/*   Updated: 2025/04/28 14:42:59 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* array, int length, void (*func)(T&))
{
	for (int i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

template <typename T>
void iter(const T* array, int length, void (*func)(const T&))
{
	for (int i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif
