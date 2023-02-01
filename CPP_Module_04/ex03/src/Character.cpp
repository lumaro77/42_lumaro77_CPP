/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:55:31 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 13:53:13 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): 
	_name("Unknown"),
	_nbMaterials(0),
	_nbBin(0)
{
    std::cout << "Character default constructor called" << std::endl;
	for (unsigned int i = 0; i < Character::_maxMaterials; ++i)
		_materials[i] = nullptr;
	for (unsigned int i = 0; i < Character::_maxBin; ++i)
		_bin[i] = nullptr;
	return ;
}

Character::Character(const std::string &name): 
	_name(name),
	_nbMaterials(0),
	_nbBin(0)
{
    std::cout << "Character named constructor called" << std::endl;
	for (unsigned int i = 0; i < Character::_maxMaterials; ++i)
		_materials[i] = nullptr;
	for (unsigned int i = 0; i < Character::_maxBin; ++i)
		_bin[i] = nullptr;
    return ;
}

Character::~Character(void) 
{
	this->_deleteMateria();
	this->_deleteBin();
	std::cout << "Character destructor called" << std::endl;
    return ;
}

Character::Character(const Character &character):
	_name(character._name),
	_nbMaterials(0),
	_nbBin(0)
{
	this->_cloneMateria(character);
	this->_cloneBin(character);
    std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character &Character::operator=(const Character &character)
{
	this->_name = character._name;
	this->_cloneMateria(character);
	this->_cloneBin(character);
	std::cout << "Character assignation operator called" << std::endl;
	return (*this);
}

const std::string &Character::getName(void) const
{
	std::cout << "Character getName getter called" << std::endl;
	return (this->_name);
}

void Character::equip(AMateria *materia) 
{
	std::cout << "Character equip service called" << std::endl;
	if (materia == nullptr) {
		std::cout << "No valid materia!" << std::endl;
	} else if (this->_nbMaterials < Character::_maxMaterials) {
		this->_materials[this->_nbMaterials] = materia;
		this->_nbMaterials++;
	} else {
		delete materia;
		std::cout << "Can't equip another material!" << std::endl;}
	return ;
}

void Character::unequip(int idx)
{
	std::cout << "Character unequip service called" << std::endl;
	if (!this->_materiaValidIndex(idx) || !this->_materials[idx]) {
		return;
	} else if (this->_nbBin >= Character::_maxBin) {
		std::cout << "Can't unequip another material!" << std::endl;
	} else {
		this->_bin[this->_nbBin] = this->_materials[idx];
		this->_nbBin++;
		this->_nbMaterials--;
		while (static_cast<unsigned int>(++idx) < Character::_maxMaterials)
			this->_materials[idx - 1] = this->_materials[idx];
		this->_materials[Character::_maxMaterials - 1] = nullptr;
	}
	return ;
}

void Character::use(int idx, ICharacter &target)
{
	std::cout << "Character use service called" << std::endl;
	if (!this->_materiaValidIndex(idx) || !this->_materials[idx])
		return;
	this->_materials[idx]->use(target);
}

bool Character::_materiaValidIndex(const int idx) const
{
	if (idx < 0)
		return false;
	if (idx >= Character::_maxMaterials)
		return (false);
	return true;
}

void Character::_deleteMateria(void)
{
	for (int i = 0; i < Character::_maxMaterials; i++)
		if (this->_materials[i]) {
			delete this->_materials[i];
			this->_materials[i] = nullptr;
		}
	this->_nbMaterials = 0;
	return ;
}

void Character::_cloneMateria(const Character &character)
{
	if (this->_nbMaterials > 0)
		this->_deleteMateria();
	for (unsigned int i = 0; i < Character::_maxMaterials; i++) {
		if (character._materials[i])
			this->_materials[i] = character._materials[i]->clone();
		else
			this->_materials[i] = nullptr; }
	this->_nbMaterials = character._nbMaterials;
	return ;
}

void Character::_deleteBin(void)
{
	for (int i = 0; i < Character::_maxBin; i++)
		if (this->_bin[i]) {
			delete this->_bin[i];
			this->_bin[i] = nullptr; }
	this->_nbBin = 0;
	return ;
}

void Character::_cloneBin(const Character &character)
{
	if (this->_nbBin > 0)
		this->_deleteBin();
	for (unsigned int i = 0; i < Character::_maxBin; i++) {
		if (character._bin[i])
			this->_bin[i] = character._bin[i]->clone();
		else
			this->_bin[i] = nullptr; }
	this->_nbBin = character._nbBin;
	return ;
}
