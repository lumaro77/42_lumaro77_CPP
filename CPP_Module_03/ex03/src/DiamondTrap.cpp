/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:36:23 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:42:45 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
    ClapTrap(),
	FragTrap(),
    ScavTrap(),
    _name("Unknown")
{
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_initHitPoints();
	this->_energyPoints = ScavTrap::_initEnergyPoints();
	this->_attackDamage = FragTrap::_initAttackPoints();
    std::cout << "DiamondTrap default constructor called." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const std::string name):
    ClapTrap(),
    FragTrap(),
    ScavTrap(),
    _name(name)
{
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_initHitPoints();
	this->_energyPoints = ScavTrap::_initEnergyPoints();
	this->_attackDamage = FragTrap::_initAttackPoints();
    std::cout << this->_name << " DiamondTrap named constructor called." << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << this->_name << " DiamondTrap destructor called." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap):
    ClapTrap(diamondTrap._name + "_clap_name"),
	_name(diamondTrap._name)
{
	this->_hitPoints = diamondTrap._hitPoints;
	this->_energyPoints = diamondTrap._energyPoints;
	this->_attackDamage = diamondTrap._attackDamage;
	std::cout << this->_name << " DiamondTrap copy construct called." << std::endl;
	return ;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	ClapTrap::_name = diamondTrap._name + "_clap_name";
    this->_name = diamondTrap._name;
	this->_hitPoints = diamondTrap._hitPoints;
	this->_energyPoints = diamondTrap._energyPoints;
	this->_attackDamage = diamondTrap._attackDamage;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	return ;
}

void    DiamondTrap::whoAmI(void) const
{
    std::cout << "I am a DiamondTrap named " << this->_name; 
    std::cout << ", ClapTrap name: " << ClapTrap::_name;
    std::cout << std::endl;
	return ;
}