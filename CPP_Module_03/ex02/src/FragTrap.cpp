/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:17:08 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:56:04 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
	return ;
}

FragTrap::FragTrap(const std::string name):
	ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << this->_name << " FragTrap named constructor called." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &cpy):
	ClapTrap()
{
	*this = cpy;
	std::cout << this->_name << " FragTrap copy constructor called." << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->_name << " FragTrap destructor called" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &fragTrap)
{
	this->_attackDamage = fragTrap._attackDamage;
	this->_energyPoints = fragTrap._energyPoints;
	this->_hitPoints = fragTrap._hitPoints;
	this->_name = fragTrap._name;
	return (*this);
}

int FragTrap::_checkEnergyPoints(void) const
{
	if (this->_energyPoints > 0)
		return (1);
	else
		std::cout << this->_name << " FragTrap has no more energy points." << std::endl;
	return (0);
}

int FragTrap::_checkHitPoints(void) const
{
	if (this->_hitPoints > 0)
		return (1);
	else
		std::cout << this->_name << " FragTrap has no more hit points." << std::endl;
	return (0);
}

void FragTrap::attack(const std::string &target)
{
	if (!_checkEnergyPoints() || !_checkHitPoints())
		return ;
	this->_energyPoints -= 1;
	
	std::cout << "FragTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage;
	std::cout << " points of damage!" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void) const
{
	if (!_checkEnergyPoints() || !_checkHitPoints())
		return ;
	
	std::cout << "FragTrap " << this->_name; 
	std::cout << " Yeaaah! Asking for a high five!" << std::endl;
	return ;
}
