/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:28:50 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/08 12:08:12 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): 
    Animal("Dog"),
	_brain_dog(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain_dog;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &dog):
	Animal(),
	_brain_dog(new Brain(*dog._brain_dog))
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
	return ;
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = dog._type;
	*this->_brain_dog = *dog._brain_dog;
	return (*this);
}

Brain *Dog::getBrain(void) const
{
	return this->_brain_dog;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bof bof" << std::endl;
	return ;
}