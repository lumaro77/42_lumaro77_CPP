/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:53:16 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/06 18:35:55 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal constructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(const std::string &type)
{
    std::cout << "AAnimal constructor called" << std::endl;
    this->_type = type;
    return ;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(const AAnimal &aAnimal)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = aAnimal;
    return ;
}

AAnimal &AAnimal::operator=(const AAnimal &aAnimal)
{
    std::cout << "AAnimal assignation operator called" << std::endl;
    this->_type = aAnimal._type;
    return (*this);
}

std::string AAnimal::getType(void) const
{   return this->_type; }
