/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:40:50 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/05 14:25:38 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void reportScavTrap(ScavTrap *scavTrap)
{
	std::cout << std::endl;
	std::cout << scavTrap->getName() << " Report" << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap hit points: " << scavTrap->getHitPoints() << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap energy points: " << scavTrap->getEnergyPoints() << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap attack damage: " << scavTrap->getAttackDamage() << std::endl;
}

static void reportFragTrap(FragTrap *fragTrap)
{
	std::cout << std::endl;
	std::cout << fragTrap->getName() << " Report" << std::endl;
	std::cout << fragTrap->getName() << " FragTrap hit points: " << fragTrap->getHitPoints() << std::endl;
	std::cout << fragTrap->getName() << " FragTrap energy points: " << fragTrap->getEnergyPoints() << std::endl;
	std::cout << fragTrap->getName() << " FragTrap attack damage: " << fragTrap->getAttackDamage() << std::endl;
}

int main()
{
	{
		std::cout << "CASE 0. CHECKING FRAGTRAP." << std::endl;
		FragTrap oktoFragTrap("Okto");
		oktoFragTrap.highFivesGuys();
		reportFragTrap(&oktoFragTrap);
	}
	
	{
	 	std::cout << "CASE 1: CHECKING HIT POINTS i." << std::endl;
		ScavTrap studentScavTrap("Student");
		FragTrap oktoFragTrap("Okto");
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);

		oktoFragTrap.highFivesGuys();
		while (studentScavTrap.getHitPoints() > 0)
		{
			oktoFragTrap.attack(studentScavTrap.getName());
			studentScavTrap.takeDamage(oktoFragTrap.getAttackDamage());
			reportFragTrap(&oktoFragTrap);
			reportScavTrap(&studentScavTrap);
		}
		oktoFragTrap.attack(studentScavTrap.getName());
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);

		studentScavTrap.attack(oktoFragTrap.getName());
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);
		studentScavTrap.guardGate();
	}

	{
		std::cout << "CASE 2: CHECKING HIT POINTS ii." << std::endl;
		ScavTrap studentScavTrap("Student");
		FragTrap oktoFragTrap("Okto");
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);
		
		oktoFragTrap.highFivesGuys();
		while (oktoFragTrap.getHitPoints() > 0)
		{
			studentScavTrap.attack(oktoFragTrap.getName());
			oktoFragTrap.takeDamage(studentScavTrap.getAttackDamage());
			reportFragTrap(&oktoFragTrap);
			reportScavTrap(&studentScavTrap);
		}
		oktoFragTrap.attack(studentScavTrap.getName());
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);

		studentScavTrap.attack(oktoFragTrap.getName());
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);
		studentScavTrap.guardGate();
	}

	{
		std::cout << "CASE 3: CHECKING REPAIR." << std::endl;
		ScavTrap studentScavTrap("Student");
		FragTrap oktoFragTrap("Okto");
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);
		
		oktoFragTrap.highFivesGuys();
		
		oktoFragTrap.attack(studentScavTrap.getName());
		studentScavTrap.takeDamage(oktoFragTrap.getAttackDamage());
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);
	
		studentScavTrap.beRepaired(oktoFragTrap.getAttackDamage());
		reportFragTrap(&oktoFragTrap);
		reportScavTrap(&studentScavTrap);
		studentScavTrap.guardGate();
	}
}