/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:39:42 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/13 14:06:14 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cstdlib>
#include "iter.hpp"

int main(void)
{
	int iarr[6] = {1, 2, 3, 4, 5, 6};
	std::string sarr[6] = {"May", "the", "force", "be", "with", "you"};
	float farr[6] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f};

	std::cout << "int array: " << std::endl;
	iter(iarr, 6, print);
	std::cout << std::endl;

	std::cout << "string array: " << std::endl;
	iter(sarr, 6, print);
	std::cout << std::endl;

	std::cout << "float array: " << std::endl;
	iter(farr, 6, print);
	std::cout << std::endl;
	
	return (0);
}