/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:17:14 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:46:17 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << "Harl default constructor called" << std::endl;
	return ;
}

Harl::~Harl(void) {
	std::cout << "Harl destructor called" << std::endl;
	return ;
}

void Harl::_debug(void)
{ std::cout << "Harl: Hi!" << std::endl; }

void Harl::_info(void)
{ std::cout << "Harl: My robot name is Harl!" << std::endl; }

void Harl::_warning(void)
{ std::cout <<  "Harl: I am low battery!" << std::endl; }

void	Harl::_error( void ) 
{ std::cout << "Harl: I am dead :(!" << std::endl; }

void	Harl::complain(std:: string level)
{
	std::string	str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};	
	void (Harl::*fun[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	const int maxFun = 4;

    int i = 0;
    while (i < maxFun && str[i].compare(level))
        i++;
  	switch (i){
		case 0:
			(this->*(fun[0]))();
		case 1:
			(this->*(fun[1]))();
		case 2:
			(this->*(fun[2]))();
		case 3:
			(this->*(fun[3]))();
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]"; 
			std::cout << std::endl;
	}
}