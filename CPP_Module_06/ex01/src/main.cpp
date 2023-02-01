/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:56 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/13 13:55:54 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>
#include "data.h"

uintptr_t serialize(Data* ptr)
{ return reinterpret_cast<uintptr_t>(ptr); }

Data *deserialize(uintptr_t raw)
{ return reinterpret_cast<Data *>(raw); }

int main(void)
{
	Data* ptr = new Data;

	ptr->i = 42;
	ptr->f = 3.1415f;
	ptr->str = "Okto";

	std::cout << "int in data: " << ptr->i << std::endl;
	std::cout << "float in data: " << ptr->f << std::endl;
	std::cout << "str in data: " << ptr->str << std::endl;

	std::cout << "Size of Data: " << sizeof(ptr) << std::endl;
	std::cout << "Deserialized: " << ptr << std::endl;
	uintptr_t serialized = serialize(ptr);
	std::cout << "Serialized: " << serialized << std::endl;
	std::cout << "Deserialized: " << deserialize(serialized) << std::endl;

	std::cout << "int in deserialize data: " << ptr->i << std::endl;
	std::cout << "float in deserialize data: " << ptr->f << std::endl;
	std::cout << "str in deserialize data: " << ptr->str << std::endl;

	delete ptr;
}