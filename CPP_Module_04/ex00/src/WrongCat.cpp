/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:33:46 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 11:17:25 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->_type = "WrongCat";
    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wrongCat;
    return ;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
    std::cout << "WrongCat assignation operator called" << std::endl;
    this->_type = wrongcat._type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meu meu" << std::endl;
    return ;
}
