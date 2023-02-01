/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:56 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/13 13:57:12 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Base.hpp>

Base::~Base(void)
{
	std::cout << "Base destructor called." << std::endl;
	return ;
}

Base *generate(void)
{
	srand(time(NULL));
	switch(rand() % 3) {
		case 0:
			std::cout << "Type A created." << std::endl;
			return new A;
		case 1:
			std::cout << "Type B created." << std::endl;
			return new B;
		case 2:
			std::cout << "Type C created." << std::endl;
			return new C;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer is type A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer is type B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer is type C." << std::endl;
	else
		std::cout << "Cannot identify pointer type." << std::endl;
	return ;
}

void identify(Base& p)
{
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (const std::exception &e) {
		try {
			B b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		} catch (const std::exception &e) {
			try {
				C c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			} catch (const std::exception &e) {
				std::cout << "Cannot identify reference type." << std::endl;
			}
		}
	}	
	return ;
}
