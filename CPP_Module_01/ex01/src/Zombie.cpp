/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:35:58 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 08:45:46 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie default constructor called." << std::endl;
	return ;
}

Zombie::~Zombie(void) 
{
	std::cout << "Zombie destructor called." << std::endl;	
}

Zombie::Zombie(const Zombie &zombie):
	_name(zombie._name)
{
	std::cout << "Zombie copy constructor called." << std::endl;
	return ;
}

Zombie & Zombie::operator=(const Zombie &zombie)
{
	std::cout << "Zombie assignation operator called." << std::endl;
	if (this == &zombie)
		return (*this); 
	this->_name = zombie._name;
	return (*this); 
}

void Zombie::setName(const std::string &name)
{
	std::cout << "Zombie setName called." << std::endl;
	this->_name = name;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}