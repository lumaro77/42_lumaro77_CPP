/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:39:47 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/13 14:05:39 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <iostream>

template<class T> 
void print(T &element)
{ std::cout << element << std::endl; }

template <typename T>
void iter(T *array, size_t arraySize, void (*fun)(T &)) {
	for (size_t i = 0; i < arraySize; i++)
		fun(array[i]); }

#endif