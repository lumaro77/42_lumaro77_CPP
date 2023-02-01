/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:39:32 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:37:11 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):
    ClapTrap()
{
	this->_hitPoints = this->_initHitPoints();
	this->_energyPoints = this->_initEnergyPoints();
	this->_attackDamage = this->_initAttackPoints();
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string name):
    ClapTrap(name)
{
	this->_hitPoints = this->_initHitPoints();
	this->_energyPoints = this->_initEnergyPoints();
	this->_attackDamage = this->_initAttackPoints();
	std::cout << this->_name << " ScavTrap named constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_name << " ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap):
    ClapTrap(scavTrap)
{
	*this = scavTrap;
	std::cout << this->_name << " ScavTrap copy constructor called." << std::endl;
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

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->_name;
	std::cout << " Gate keeper mode activate!.";
	std::cout << std::endl;
	return ;
}

unsigned int ScavTrap::_initHitPoints(void) const
{ return (100); }

unsigned int ScavTrap::_initEnergyPoints(void) const
{ return (50); }

unsigned int ScavTrap::_initAttackPoints(void) const
{ return (20); }

