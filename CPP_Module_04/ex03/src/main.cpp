/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:34:54 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:01:57 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	{
		std::cout << std::endl;
		std::cout << "CASE SUBJECT" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	
	{	
		std::cout << std::endl;
		std::cout << "CASE CHARACTER" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		ICharacter *me = new Character("Okto");
		me->unequip(1);
		delete me;
	}
	
	{	
		std::cout << std::endl;
		std::cout << "CASE MATERIASOURCE" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		ICharacter *me = new Character("Okto");
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->unequip(0);
		me->unequip(1);
		delete src;
		delete me;
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE CHARACTER ASSIGNATION" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		IMateriaSource *src = new MateriaSource();
		Character *p1 = new Character("Okto");
		Character *p2 = new Character("Student");
		AMateria *tmp;
		src->learnMateria(new Ice());	 
		tmp = src->createMateria("ice"); 
		p1->equip(tmp);					 
		*p2 = *p1;						 
		p1->use(0, *p2);				 
		p2->use(0, *p1);				 
		delete p1;
		delete p2;
		delete src;
	}

	{
		std::cout << std::endl;
		std::cout << "CASE CHARACTER COPY" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		IMateriaSource *src = new MateriaSource();
		Character *p1 = new Character("Okto");
		Character p2(*p1);
		AMateria *tmp;
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		p1->use(0, p2);
		p2.use(0, *p1);
		delete p1;
		delete tmp;
		delete src;
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE USING UNAVAILABLE" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		ICharacter *p1 = new Character("Okto");
		ICharacter *p2 = new Character("Student");
		p1->use(-1, *p2);
		p1->use(0, *p2);
		p1->use(10, *p2);
		delete p1;
		delete p2;
	}

	{
		std::cout << std::endl;
		std::cout << "CASE DEEP COPY" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		IMateriaSource*	myMateriaSource  = new MateriaSource;
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Ice());

		ICharacter*		me = new Character("me");
		ICharacter*		he = new Character("he");

		AMateria*		myMateria;
		myMateria = myMateriaSource->createMateria("ice");

		me->use(0, *he);
		me->equip(myMateria);
		me->use(0, *he);
		ICharacter	*copy(me);
		copy->use(0, *he);
		me->use(0, *he);
		copy->unequip(0);
		std::cout << "After unequipping" << std::endl;
		me->use(0, *he);

		delete myMateriaSource;
		delete me;
		delete he;
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE LEARN TOO MUCH" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;

		IMateriaSource* myMateriaSource = new MateriaSource();
		myMateriaSource->learnMateria(new Ice());
		myMateriaSource->learnMateria(new Ice());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		myMateriaSource->learnMateria(new Cure());
		delete myMateriaSource;
	}

	{

		std::cout << std::endl;
		std::cout << "CASE EQUIP TOO MUCH" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;

		IMateriaSource* myMateriaSource = new MateriaSource();
		myMateriaSource->learnMateria(new Ice());
		myMateriaSource->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* myMateria;
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("cure");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("cure");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("cure");
		me->equip(myMateria);
	
		delete me;
		delete myMateriaSource;
	}

	{
		std::cout << std::endl;
		std::cout << "CASE UNEQUIP TOO MUCH" << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;

		IMateriaSource* myMateriaSource = new MateriaSource();
		myMateriaSource->learnMateria(new Ice());
		myMateriaSource->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* myMateria;
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("cure");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("cure");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		me->unequip(3);
		me->unequip(2);
		me->unequip(0);
		me->unequip(0);
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("cure");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("cure");
		me->equip(myMateria);
		myMateria = myMateriaSource->createMateria("ice");
		me->equip(myMateria);
		me->unequip(0);
		me->unequip(0);
		me->unequip(0);
		me->unequip(0);

		delete me;
		delete myMateriaSource;
	}
}