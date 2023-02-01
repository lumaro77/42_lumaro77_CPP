/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:16:04 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 08:52:25 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str; 
	std::string &stringREF = str;

	std::cout << "String: " << &str << std::endl;
	std::cout << "Pointer: " << &stringPTR << std::endl; 
	std::cout << "Reference: " << &stringREF << std::endl;

	std::cout << "String variable value: " << str << std::endl;
	std::cout << "Pointer pointed value: " << *stringPTR << std::endl; 
	std::cout << "Reference pointed value: " << stringREF << std::endl;

	return (0);
}