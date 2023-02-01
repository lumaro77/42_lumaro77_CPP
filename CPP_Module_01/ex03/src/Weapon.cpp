/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:16:07 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:08:29 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << "Weapon default constructor called." << std::endl;
	return ;
}

Weapon::Weapon(std::string type):
	_type(type)
{
	std::cout << "Weapon parameter constructor called." << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor called." << std::endl;
	return ;
}

Weapon::Weapon(const Weapon &weapon)
{
	std::cout << "Weapon copy constructor called." << std::endl;
	*this = weapon;
	return ;
}

Weapon &Weapon::operator=(const Weapon &weapon)
{
	std::cout << "Weapon assignation operator called." << std::endl;
	if (this == &weapon)
		return (*this);
	this->_type = weapon._type;
	return (*this);
}

const std::string & Weapon::getType(void) const
{ return (this->_type); }

void Weapon::setType(std::string type)
{ this->_type = type; }