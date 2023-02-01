/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:05:15 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/04 17:11:54 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

static void reportClapTrap(ClapTrap *clapTrap)
{
	std::cout << std::endl;
	std::cout << clapTrap->getName() << " Report" << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap hit points: " << clapTrap->getHitPoints() << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap energy points: " << clapTrap->getEnergyPoints() << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap attack damage: " << clapTrap->getAttackDamage() << std::endl;
}

int main(void)
{
	{	
		std::cout << "CASE: ENERGY POINTS." << std::endl;
		std::cout << std::endl;
		ClapTrap clapTrapOkto("Okto");
		ClapTrap clapTrapStudent("Student");
		std::cout << std::endl;
		
		while (clapTrapOkto.getEnergyPoints() > 0)
		{
			clapTrapOkto.attack(clapTrapStudent.getName());
			clapTrapStudent.takeDamage(clapTrapOkto.getAttackDamage());
			reportClapTrap(&clapTrapOkto);
			reportClapTrap(&clapTrapStudent);
			std::cout << std::endl;
		}
		clapTrapOkto.attack(clapTrapStudent.getName());
		std::cout << std::endl;

		reportClapTrap(&clapTrapOkto);
		reportClapTrap(&clapTrapStudent);
		std::cout << std::endl;
	}

	{
		std::cout << "CASE: REPAIR." << std::endl;
		std::cout << std::endl;
		ClapTrap clapTrapOkto("Okto");
		ClapTrap clapTrapStudent("Student");
		std::cout << std::endl;
		
		while (clapTrapOkto.getEnergyPoints() > 0)
		{
			clapTrapOkto.attack(clapTrapStudent.getName());
			clapTrapStudent.takeDamage(clapTrapOkto.getAttackDamage() + 5);
			clapTrapStudent.beRepaired(1);
			reportClapTrap(&clapTrapOkto);
			reportClapTrap(&clapTrapStudent);
			std::cout << std::endl;
		}
		clapTrapOkto.attack(clapTrapStudent.getName());
		std::cout << std::endl;

		reportClapTrap(&clapTrapOkto);
		reportClapTrap(&clapTrapStudent);
		std::cout << std::endl;
	}

}