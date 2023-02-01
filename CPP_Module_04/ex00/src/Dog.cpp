/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:28:50 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:28:05 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): 
    Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &dog):
	Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
	return ;
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = dog._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bof bof" << std::endl;
	return ;
}