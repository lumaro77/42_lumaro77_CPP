/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:35:58 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 08:37:40 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void):
	_name("Unnamed zombie")
{
	std::cout << this->_name << ": default constructor called." << std::endl;
	return ;
}

Zombie::Zombie(const std::string name):
	_name(name)
{
	std::cout << this->_name << ": parameter constructor called." << std::endl;
	return ;
}

Zombie::~Zombie(void) 
{
	std::cout << this->_name << ": destructor called." << std::endl;
	return ;
}

Zombie::Zombie(const Zombie &zombie):
	_name(zombie._name)
{
	std::cout << this->_name << ": copy constructor called." << std::endl;
	return ;
}

Zombie & Zombie::operator=(const Zombie &zombie)
{
	std::cout << this->_name << ": assignation operator called." << std::endl;
	if (this == &zombie)
		return (*this); 
	this->_name = zombie._name;
	return (*this); 
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
