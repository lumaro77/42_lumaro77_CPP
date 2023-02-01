/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:34:18 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/12 22:11:17 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <array>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main(void)
{
{	
	std::cout << std::endl;
	std::cout << "CASE VECTOR" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 6; i++)
		v.push_back(i);
	std::cout << "Int Vector: {";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v.at(i) << " ";
	std::cout << "}" << std::endl;

	try	{
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "easyfind easily found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "easyfind says: "<< e.what() << std::endl; }

	try {
		std::vector<int>::iterator it = easyfind(v, 6);
		std::cout << "easyfind easily found:" << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "easyfind says: "<< e.what() << std::endl; }
}

{	
	std::cout << std::endl;
	std::cout << "CASE ARRAY" << std::endl;
	std::array<int, 6> a = {0, 1, 2, 3, 4, 5};
	std::cout << "Int Array: {";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a.at(i) << " ";
	std::cout << "}" << std::endl;

	try	{
		std::cout << "easyfind easily found at: ";
		std::cout << std::distance(a.begin(), easyfind(a, 3)) << std::endl;
	} catch (std::exception &e) {
		std::cout << "easyfind says: "<< e.what() << std::endl; }

	try	{
		std::cout << std::distance(a.begin(), easyfind(a, 6)) << std::endl;
		std::cout << "easyfind easily found at: ";
	} catch (std::exception &e) {
		std::cout << "easyfind says: "<< e.what() << std::endl; }
}

{	
	std::cout << std::endl;
	std::cout << "CASE LIST" << std::endl;
	std::list<int> l;
	for (int i = 0; i < 6; i++)
		l.push_back(i);
	std::cout << "Int List: {";
	std::list<int>::iterator it = l.begin();
    for(int i=0; i<6; i++)
		std::cout << *it++ << " ";    
	std::cout << "}" << std::endl;

	try	{
		std::list<int>::iterator it = easyfind(l, 3);
		std::cout << "easyfind easily found: " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "easyfind says: "<< e.what() << std::endl; }

	try {
		std::list<int>::iterator it = easyfind(l, 6);
		std::cout << "easyfind easily found:" << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "easyfind says: "<< e.what() << std::endl; }
}

    return (0);
}