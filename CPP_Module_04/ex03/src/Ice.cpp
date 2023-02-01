/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:26:40 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:34:58 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Ice.hpp>

Ice::Ice(void):
	AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::~Ice(void) 
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice::Ice(const Ice &ice):
	AMateria(ice._type)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = ice;
	return ;
}

Ice &Ice::operator=(const Ice &ice)
{
	std::cout << "Ice assignation operator called" << std::endl;
	this->_type = ice._type;
	return (*this) ;
}

Ice *Ice::clone(void) const
{
	std::cout << "Ice clone service called" << std::endl;
	return new Ice() ;
}

void Ice::use(ICharacter &target) 
{
	std::cout << "Ice use service called" << std::endl;
	std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
	return ;
}
