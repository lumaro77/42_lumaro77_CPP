/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:28:08 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:35:43 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MateriaSource.hpp>

MateriaSource::MateriaSource(void):
	_nbMaterials(0)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (unsigned int i = 0; i < MateriaSource::_maxMaterials; ++i)
		_materials[i] = nullptr;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	this->_clearMateriaArray();
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	this->_cloneMateriaArray(materiaSource);
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	this->_copyMateriaArray(materiaSource);
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	std::cout << "MateriaSource learnMateria service called" << std::endl;
	if (materia == nullptr) {
		std::cout << "No valid materia!" << std::endl;
	} else if (_nbMaterials < MateriaSource::_maxMaterials) {
		this->_materials[this->_nbMaterials] = materia;
		this->_nbMaterials++;
	} else {
		delete materia;
		std::cout << "Can't learn new materials!" << std::endl;	}
	return ; 
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	std::cout << "MateriaSource createMateria service called" << std::endl;
	for (unsigned int i = 0; i < this->_nbMaterials; ++i) {
		if (this->_materials[i]->getType() == type)
			return (this->_materials[i]->clone()); }
	return (nullptr);
}

void MateriaSource::_cloneMateriaArray(const MateriaSource &materiaSource)
{
	if (this->_nbMaterials > 0)
		this->_clearMateriaArray();
	for (unsigned int i = 0; i < materiaSource._nbMaterials; i++)
		this->_materials[i] = materiaSource._materials[i]->clone();
	this->_nbMaterials = materiaSource._nbMaterials;
	return ;
}

void MateriaSource::_copyMateriaArray(const MateriaSource &materiaSource)
{
	if (this->_nbMaterials > 0)
		this->_clearMateriaArray();
	for (unsigned int i = 0; i < materiaSource._nbMaterials; i++)
		this->_materials[i] = materiaSource._materials[i];
	this->_nbMaterials = materiaSource._nbMaterials;
	return ;
}

void MateriaSource::_clearMateriaArray(void)
{
	for (unsigned int i = 0; i < MateriaSource::_maxMaterials; i++)
		if (this->_materials[i] != nullptr)
			delete this->_materials[i];
	this->_nbMaterials = 0;
	return ;
}