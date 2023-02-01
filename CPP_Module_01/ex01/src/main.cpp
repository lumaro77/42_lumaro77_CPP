/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:50:20 by lmartin2          #+#    #+#             */
/*   Updated: 2022/12/12 13:09:46 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	const int N = 7;

	std::cout << "Creating "<< N << " zombie Alpha on the heap via zombieHode." << std::endl;
	Zombie *zombie = zombieHorde(N, "Alpha");
	std::cout << std::endl;
	
	std::cout << "Calling announce() on each zombie." << std::endl;
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	std::cout << std::endl;
 	
	std::cout << "Deleting zombieHode." << std::endl;  
    delete [] zombie;
    return (0);
}