/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:42:49 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 08:58:45 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(void)
{
	std::cout << "HumanA default constructor called." << std::endl;
	return ;
}

HumanA::HumanA(std::string name, Weapon &weapon):
	_name(name),
	_weapon(&weapon)
{
	std::cout << "HumanA parameter constructor called." << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor called." << std::endl;
	return ;
}

HumanA::HumanA(const HumanA &humanA)
{
	std::cout << "HumanA copy constructor called." << std::endl;
	*this = humanA;
	return ;
}

HumanA &HumanA::operator=(const HumanA &humanA)
{
	std::cout << "HumanA assignation operator called." << std::endl;
	if (this == &humanA)
		return (*this);
	this->_name = humanA._name;
	this->_weapon = humanA._weapon;
	return (*this);
}

void HumanA::attack(void) const
{
	std::cout << this->_name;
	std::cout << " attacks with their " << this->_weapon->getType();
	std::cout << std::endl;
	return ;
}