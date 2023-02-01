/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:08:51 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 11:16:01 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal constructor called" << std::endl;
    return ;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
    return ;
}

Animal &Animal::operator=(const Animal &animal)
{
    std::cout << "Animal assignation operator called" << std::endl;
    this->_type = animal._type;
    return (*this);
}

std::string Animal::getType(void) const
{   return this->_type; }

void Animal::makeSound(void) const
{
	std::cout << "Weeeeee weeeee I am an unicorn!" << std::endl;
    return ;
}