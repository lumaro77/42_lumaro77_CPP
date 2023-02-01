/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:32:51 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 11:20:36 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
    Animal("Cat"),
    _brain_cat(new Brain())
{
    std::cout << "Cat constructor called" << std::endl;
    return ;
}

Cat::~Cat(void)
{
    delete this->_brain_cat;
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat &cat):
    Animal(),
    _brain_cat(new Brain(*cat._brain_cat))
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
    return ;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat assignation operator called" << std::endl;
    this->_type = cat._type;
    return (*this);
}

Brain *Cat::getBrain() const
{
	return this->_brain_cat;
}

void Cat::makeSound(void) const
{
	std::cout << "Meu meu" << std::endl;
    return ;
}
