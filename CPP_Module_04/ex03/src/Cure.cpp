/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:24:15 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/16 13:19:00 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cure.hpp>

Cure::Cure(void):
	AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	return ;
};

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
};

Cure::Cure(const Cure &cure):
	AMateria(cure._type)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = cure;
	return ;
};

Cure &Cure::operator=(const Cure &cure)
{
	std::cout << "Cure assignation operator called" << std::endl;
	this->_type = cure._type;
	return *this ;
}

Cure *Cure::clone(void) const
{
	std::cout << "Cure clone service called" << std::endl;
	return new Cure() ;
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure use service called" << std::endl;
	std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
	return ;
}