/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:05:12 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:40:21 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name("Unknown"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap default construct called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string name):
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << this->_name << " ClapTrap named construct called." << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->_name << " ClapTrap destructor called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap):
	_name(clapTrap._name),
	_hitPoints(clapTrap._hitPoints),
	_energyPoints(clapTrap._energyPoints),
	_attackDamage(clapTrap._attackDamage)
{
	std::cout << this->_name << " ClapTrap copy construct called." << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	return (*this);
}

std::string ClapTrap::getName(void) const
{ return (this->_name); }  

unsigned int ClapTrap::getHitPoints(void) const
{ return (this->_hitPoints); }

unsigned int ClapTrap::getEnergyPoints(void) const
{ return (this->_energyPoints); }

unsigned int ClapTrap::getAttackDamage(void) const
{ return (this->_attackDamage); }

void ClapTrap::attack(const std::string &target) {

	if (!_checkEnergyPoints() || !_checkHitPoints())
			return ;
	this->_energyPoints -= 1;

	std::cout << "ClapTrap " << this->_name; 
	std::cout << " attacking " << target;
	std::cout << ", causing " << this->_attackDamage;
	std::cout << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount) {

	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;

	std::cout << "ClapTrap " << this->_name;
	std::cout << " took " << amount;
	std::cout << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (!_checkEnergyPoints() || !_checkHitPoints())
			return ;
	this->_energyPoints -= 1;
	this->_hitPoints += amount;

	std::cout << "ClapTrap " << this->_name;
	std::cout << " repaired by " << amount;
	std::cout << " points of damage!" << std::endl;
	return ;
}

int ClapTrap::_checkEnergyPoints(void) const
{
	if (this->_energyPoints > 0)
		return (1);
	else
		std::cout << this->_name << " ClapTrap has no more energy points." << std::endl;
	return (0);
}

int ClapTrap::_checkHitPoints(void) const
{
	if (this->_hitPoints > 0)
		return (1);
	else
		std::cout << this->_name << " ClapTrap has no more hit points." << std::endl;
	return (0);
}