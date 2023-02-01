/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:05:15 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/04 17:12:50 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void reportClapTrap(ClapTrap *clapTrap)
{
	std::cout << std::endl;
	std::cout << clapTrap->getName() << " Report" << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap hit points: " << clapTrap->getHitPoints() << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap energy points: " << clapTrap->getEnergyPoints() << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap attack damage: " << clapTrap->getAttackDamage() << std::endl;
}

static void reportScavTrap(ScavTrap *scavTrap)
{
	std::cout << std::endl;
	std::cout << scavTrap->getName() << " Report" << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap hit points: " << scavTrap->getHitPoints() << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap energy points: " << scavTrap->getEnergyPoints() << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap attack damage: " << scavTrap->getAttackDamage() << std::endl;
}

int main(){
	{
		std::cout << "CASE 0. CHECKING SCAVTRAP." <<  std::endl;
		ScavTrap scavTrapOkto("Okto");
		reportScavTrap(&scavTrapOkto);
		scavTrapOkto.guardGate();
	}

	{
		std::cout <<  "CASE 1. HIT POINTS." <<  std::endl;
		ClapTrap clapTrapStudent("Student");
		ScavTrap scavTrapOkto("Okto");
		reportClapTrap(&clapTrapStudent);
		reportScavTrap(&scavTrapOkto);

		scavTrapOkto.guardGate();
		while (clapTrapStudent.getHitPoints() > 0)
		{
			scavTrapOkto.attack(clapTrapStudent.getName());
			clapTrapStudent.takeDamage(scavTrapOkto.getAttackDamage());
			reportClapTrap(&clapTrapStudent);
			reportScavTrap(&scavTrapOkto);
		}
		clapTrapStudent.attack(scavTrapOkto.getName());
		reportClapTrap(&clapTrapStudent);
		reportScavTrap(&scavTrapOkto);
	}

	{
		std::cout <<  "CASE 2. ENERGY POINTS." <<  std::endl;
		ClapTrap studentClapTrap("Student");
		ScavTrap oktoScavTrap("Okto");
		reportClapTrap(&studentClapTrap);
		reportScavTrap(&oktoScavTrap);
		
		while (oktoScavTrap.getEnergyPoints() > 0)
		{
			oktoScavTrap.attack(studentClapTrap.getName());
			studentClapTrap.takeDamage(oktoScavTrap.getAttackDamage());
			reportClapTrap(&studentClapTrap);
			reportScavTrap(&oktoScavTrap);
		}
		oktoScavTrap.attack(studentClapTrap.getName());
		reportClapTrap(&studentClapTrap);
		reportScavTrap(&oktoScavTrap);
		studentClapTrap.attack(oktoScavTrap.getName());
		reportClapTrap(&studentClapTrap);
		reportScavTrap(&oktoScavTrap);
	}

	{
		std::cout <<  "CASE 3. REPAIRS." <<  std::endl;
		ClapTrap clapTrapStudent("Student");
		ScavTrap scavTrapOkto("Okto");
		reportClapTrap(&clapTrapStudent);
		reportScavTrap(&scavTrapOkto);
		scavTrapOkto.attack(clapTrapStudent.getName());
		clapTrapStudent.takeDamage(scavTrapOkto.getAttackDamage());
		reportClapTrap(&clapTrapStudent);
		reportScavTrap(&scavTrapOkto);
		clapTrapStudent.beRepaired(3);
		reportClapTrap(&clapTrapStudent);
		reportScavTrap(&scavTrapOkto);
	}
}