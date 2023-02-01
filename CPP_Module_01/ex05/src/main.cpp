/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:17:19 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:42:46 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

static void mainExample(Harl *harl)
{
	std::cout << "Harl complain messages: " << std::endl << std::endl;;
	std::cout << "DEBUG example:" << std::endl;
	harl->complain("DEBUG");
	std::cout << std::endl;
	std::cout << "INFO example:" << std::endl;
	harl->complain("INFO");
	std::cout << std::endl;
	std::cout << "WARNING example:" << std::endl;
	harl->complain("WARNING");
	std::cout << std::endl;
	std::cout << "ERROR example:" << std::endl;
	harl->complain("ERROR");
	std::cout << std::endl;
}

static void mainMenu(void)
{
	std::cout << std::endl;
	std::cout << "Enter a level: DEBUG, INFO, WARNING or ERROR. \
	Nothing (\"\") to exit.";
	std::cout << std::endl;
}

int main(void)
{
    Harl harl;
	std::string	lineIn;
    
	mainExample(&harl);
	mainMenu();
	while (std::getline(std::cin, lineIn)){
		if (lineIn.empty())
			break ;
		harl.complain(lineIn);
		mainMenu();	}
		
	return (0);
}