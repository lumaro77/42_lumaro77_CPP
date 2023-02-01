/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:39:32 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 11:00:35 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):
    ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
	return ;
}

ScavTrap::ScavTrap(const std::string name):
    ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << this->_name << " ScavTrap named constructor called." << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_name << " ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap):
    ClapTrap()
{
	*this = scavTrap;
	std::cout << this->_name << " ScavTrap copy constructor called." << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scavTrap)
{
	this->_name = scavTrap._name;
	this->_hitPoints = scavTrap._hitPoints;
	this->_energyPoints = scavTrap._energyPoints;
	this->_attackDamage = scavTrap._attackDamage;
	return (*this);
}

int ScavTrap::_checkEnergyPoints(void) const
{
	if (this->_energyPoints > 0)
		return (1);
	else
		std::cout << this->_name << " ScavTrap has no more energy points." << std::endl;
	return (0);
}

int ScavTrap::_checkHitPoints(void) const
{
	if (this->_hitPoints > 0)
		return (1);
	else
	    std::cout << this->_name << " ScavTrap has no more hit points." << std::endl;
    return (0);
}

void ScavTrap::attack(const std::string &target)
{
	if (!_checkEnergyPoints() || !_checkHitPoints())
		return ;
	this->_energyPoints -= 1;
	
	std::cout << "ScavTrap " << this->_name; 
	std::cout << " attacks " << target; 
	std::cout << ", causing " << this->_attackDamage; 
	std::cout << " points of damage!" << std::endl;
	return ;
}

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->_name;
	std::cout << " Gate keeper mode activate!.";
	std::cout << std::endl;
	return ;
}
