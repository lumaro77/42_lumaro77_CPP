/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:32:51 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:25:16 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
    Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    return ;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat &cat):
    Animal()
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

void Cat::makeSound(void) const
{
	std::cout << "Meu meu" << std::endl;
    return ;
}
