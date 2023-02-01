/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:40:50 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/05 14:07:35 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void reportClapTrap(ClapTrap *clapTrap)
{
	std::cout << std::endl;
	std::cout << clapTrap->getName() << " Report" << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap hit points: " << clapTrap->getHitPoints() << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap energy points: " << clapTrap->getEnergyPoints() << std::endl;
	std::cout << clapTrap->getName() << " ClapTrap attack damage: " << clapTrap->getAttackDamage() << std::endl;
}

static void reportFragTrap(FragTrap *fragTrap)
{
	std::cout << std::endl;
	std::cout << fragTrap->getName() << " Report" << std::endl;
	std::cout << fragTrap->getName() << " FragTrap hit points: " << fragTrap->getHitPoints() << std::endl;
	std::cout << fragTrap->getName() << " FragTrap energy points: " << fragTrap->getEnergyPoints() << std::endl;
	std::cout << fragTrap->getName() << " FragTrap attack damage: " << fragTrap->getAttackDamage() << std::endl;
}

static void reportScavTrap(ScavTrap *scavTrap)
{
	std::cout << std::endl;
	std::cout << scavTrap->getName() << " Report" << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap hit points: " << scavTrap->getHitPoints() << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap energy points: " << scavTrap->getEnergyPoints() << std::endl;
	std::cout << scavTrap->getName() << " ScavTrap attack damage: " << scavTrap->getAttackDamage() << std::endl;
}

static void reportDiamondTrap(DiamondTrap *diamondTrap)
{
	std::cout << std::endl;
	std::cout << diamondTrap->getName() << " Report" << std::endl;
	std::cout << diamondTrap->getName() << " DiamonTrap hit points: " << diamondTrap->getHitPoints() << std::endl;
	std::cout << diamondTrap->getName() << " DiamonTrap energy points: " << diamondTrap->getEnergyPoints() << std::endl;
	std::cout << diamondTrap->getName() << " DiamonTrap attack damage: " << diamondTrap->getAttackDamage() << std::endl;
}

int main()
{
	{
		std::cout << "CASE 0. CHECKING FRAGTRAP." << std::endl;
		DiamondTrap oktoDiamondTrap("Okto");
		oktoDiamondTrap.highFivesGuys();
        oktoDiamondTrap.guardGate();
        oktoDiamondTrap.whoAmI();
        reportDiamondTrap(&oktoDiamondTrap);
	}
	
	{
		std::cout << "CASE 1: CHECKING HIT POINTS" << std::endl;
		DiamondTrap oktoDiamondTrap("OktoDiamondTrap");
		ScavTrap studentScavTrap("studentScavTrap");
		FragTrap studentFragTrap("studentFragTrap");
		ClapTrap studentClapTrap("StudentClapTrap");
		reportDiamondTrap(&oktoDiamondTrap);
		reportScavTrap(&studentScavTrap);
		reportFragTrap(&studentFragTrap);
		reportClapTrap(&studentClapTrap);

		while (oktoDiamondTrap.getHitPoints() > 0)
		{
			studentClapTrap.attack(oktoDiamondTrap.getName());
			oktoDiamondTrap.takeDamage(studentClapTrap.getAttackDamage());
			studentFragTrap.attack(oktoDiamondTrap.getName());
			oktoDiamondTrap.takeDamage(studentFragTrap.getAttackDamage());
			studentScavTrap.attack(oktoDiamondTrap.getName());
			oktoDiamondTrap.takeDamage(studentScavTrap.getAttackDamage());
			
			reportDiamondTrap(&oktoDiamondTrap);
			reportScavTrap(&studentScavTrap);
			reportFragTrap(&studentFragTrap);
			reportClapTrap(&studentClapTrap);
		}
		oktoDiamondTrap.attack(studentClapTrap.getName());
		oktoDiamondTrap.attack(studentFragTrap.getName());
		oktoDiamondTrap.attack(studentScavTrap.getName());

		reportDiamondTrap(&oktoDiamondTrap);
		reportScavTrap(&studentScavTrap);
		reportFragTrap(&studentFragTrap);
		reportClapTrap(&studentClapTrap);
	}

	{
		std::cout << "CASE 2: CHECKING REPAIR." << std::endl;
		DiamondTrap oktoDiamondTrap("OktoDiamondTrap");
		ScavTrap studentScavTrap("studentScavTrap");
		FragTrap studentFragTrap("studentFragTrap");
		ClapTrap studentClapTrap("StudentClapTrap");
			
		reportDiamondTrap(&oktoDiamondTrap);
		reportScavTrap(&studentScavTrap);
		reportFragTrap(&studentFragTrap);
		reportClapTrap(&studentClapTrap);

		studentClapTrap.attack(oktoDiamondTrap.getName());
		oktoDiamondTrap.takeDamage(studentClapTrap.getAttackDamage());
		studentFragTrap.attack(oktoDiamondTrap.getName());
		oktoDiamondTrap.takeDamage(studentFragTrap.getAttackDamage());
		studentScavTrap.attack(oktoDiamondTrap.getName());
		oktoDiamondTrap.takeDamage(studentScavTrap.getAttackDamage());

		reportDiamondTrap(&oktoDiamondTrap);
		reportScavTrap(&studentScavTrap);
		reportFragTrap(&studentFragTrap);
		reportClapTrap(&studentClapTrap);

		oktoDiamondTrap.attack(studentClapTrap.getName());
		studentClapTrap.takeDamage(oktoDiamondTrap.getAttackDamage());
		oktoDiamondTrap.attack(studentFragTrap.getName());
		studentFragTrap .takeDamage(oktoDiamondTrap.getAttackDamage());
		oktoDiamondTrap.attack(studentScavTrap.getName());
		studentScavTrap.takeDamage(oktoDiamondTrap.getAttackDamage());

		reportDiamondTrap(&oktoDiamondTrap);
		reportScavTrap(&studentScavTrap);
		reportFragTrap(&studentFragTrap);
		reportClapTrap(&studentClapTrap);

		oktoDiamondTrap.beRepaired(1);
		studentScavTrap.beRepaired(1);
		studentFragTrap.beRepaired(1);
		studentClapTrap.beRepaired(1);

		reportDiamondTrap(&oktoDiamondTrap);
		reportScavTrap(&studentScavTrap);
		reportFragTrap(&studentFragTrap);
		reportClapTrap(&studentClapTrap);
	}
}