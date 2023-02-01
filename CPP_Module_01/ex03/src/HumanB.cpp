/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:42:49 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:07:03 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{
	std::cout << "HumanB default constructor called." << std::endl;
	return ;
}

HumanB::HumanB(std::string name):
	_name(name),
	_weapon(NULL)
{
	std::cout << "HumanB parameter constructor called." << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destructor called." << std::endl;
	return ;
}

HumanB::HumanB(const HumanB &humanB)
{
	std::cout << "HumanB copy constructor called." << std::endl;
	*this = humanB;
	return ;
}

HumanB &HumanB::operator=(const HumanB &humanB)
{
	std::cout << "HumanB assignation operator called." << std::endl;
	if (this == &humanB)
		return (*this);
	this->_name = humanB._name;
	this->_weapon = humanB._weapon;
	return (*this);
}

void    HumanB::setWeapon(Weapon &weapon)
{ this->_weapon = &weapon; }

void  HumanB::attack(void) const
{
    std::cout << this->_name;
    std::cout << " attacks with their " << this->_weapon->getType();
    std::cout << std::endl;
}