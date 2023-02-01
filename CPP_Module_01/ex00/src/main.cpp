/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:16:04 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 08:43:23 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating zombie Alpha on the stack via Zombie." << std::endl;
	Zombie zombie_1 = Zombie("Alpha");
	zombie_1.announce();
	std::cout << std::endl;

	std::cout << "Creating zombie Beta on the heap via newZombie." << std::endl;
	Zombie *zombie_2 = newZombie("Beta");
	zombie_2->announce();
	delete zombie_2;
	std::cout << std::endl;

	std::cout << "Creating zombie Gamma on the stack via randomChump.";
	std::cout << std::endl;
	randomChump("Gamma");
	std::cout << std::endl;
	std::cout << "End of main." << std::endl;
	return (0);
}