/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:17:08 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:50:47 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void):
	ClapTrap()
{
	this->_hitPoints = this->_initHitPoints();
	this->_energyPoints = this->_initEnergyPoints();
	this->_attackDamage = this->_initAttackPoints();
	std::cout << "FragTrap default constructor called." << std::endl;
	return ;
}

FragTrap::FragTrap(const std::string name):
	ClapTrap(name)
{
	this->_hitPoints = this->_initHitPoints();
	this->_energyPoints = this->_initEnergyPoints();
	this->_attackDamage = this->_initAttackPoints();
	std::cout << this->_name << " FragTrap named constructor called." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &fragTrap):
	ClapTrap(fragTrap)
{
	*this = fragTrap;
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
	this->_name = fragTrap._name;
	this->_attackDamage = fragTrap._attackDamage;
	this->_energyPoints = fragTrap._energyPoints;
	this->_hitPoints = fragTrap._hitPoints;
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

void FragTrap::highFivesGuys(void) const
{
	if (!_checkEnergyPoints() || !_checkHitPoints())
		return ;
	
	std::cout << "FragTrap " << this->_name; 
	std::cout << " Yeaaah! Asking for a high five!" << std::endl;
	return ;
}

unsigned int FragTrap::_initHitPoints(void) const
{ return (100); }

unsigned int FragTrap::_initEnergyPoints(void) const
{ return (100); }

unsigned int FragTrap::_initAttackPoints(void) const
{ return (30); }