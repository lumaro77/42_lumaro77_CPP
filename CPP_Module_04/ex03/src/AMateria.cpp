/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:52:59 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/16 22:12:53 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): 
	_type("unknown") 
{
    std::cout << "AMateria default constructor called" << std::endl;
    return ;
}

AMateria::AMateria(const std::string &type): 
	_type(type) 
{
    std::cout << "AMateria parameter constructor called" << std::endl;
    return ;
}

AMateria::~AMateria(void) 
{
    std::cout << "AMateria destructor called" << std::endl;
    return ;
}

AMateria::AMateria(const AMateria &amateria)
{	
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = amateria;
	return ;
}

AMateria &AMateria::operator=(const AMateria &amateria)
{	
	std::cout << "AAnimal assignation operator called" << std::endl;
	this->_type = amateria._type; 
	return (*this) ;
}

const std::string &AMateria::getType(void) const 
{	
	std::cout << "AMateria getType getter called" << std::endl;
	return (this->_type) ;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria unreachable use service called" << std::endl;
	std::cout << this->_type << " used against " << target.getName() << std::endl;
	return ;
}
