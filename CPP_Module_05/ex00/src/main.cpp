/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:42:38 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:42:47 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "CHECK BUREAUCRAT CLASS" << std::endl;
		std::cout << std::endl;
		Bureaucrat bureaucrat_0 = Bureaucrat();
		std::cout << bureaucrat_0 << std::endl;
		std::cout << std::endl;
		Bureaucrat bureaucrat_1 = Bureaucrat("Bureaucrat_1",15);
		std::cout << bureaucrat_1 << std::endl;
		std::cout << std::endl;
		Bureaucrat bureaucrat_2 = Bureaucrat(bureaucrat_1);
		std::cout << bureaucrat_2 << std::endl;
		std::cout << std::endl;
		bureaucrat_2 = bureaucrat_0;
		std::cout << bureaucrat_2 << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "CHECK BUREAUCRAT LOW EXCEPTION" << std::endl;
		std::cout << std::endl;
		try {
			std::cout  << "Should throw a low exception:" << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 151);
			std::cout << bureaucrat << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		try	{
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 150);
			std::cout << bureaucrat << std::endl;
			std::cout  << "Should throw a low exception:" << std::endl;
			bureaucrat.demotionGrade();
			std::cout << bureaucrat << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CHECK BUREAUCRAT HIGH EXCEPTION" << std::endl;
		std::cout << std::endl;
		try{
			std::cout  << "Should throw a high exception:" << std::endl;
			Bureaucrat bureaucrat("Bureaucrat", 0);
			std::cout << bureaucrat << std::endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 1);
			std::cout << bureaucrat << std::endl;
			std::cout  << "Should throw a high exception:" << std::endl;
			bureaucrat.promotionGrade();
			std::cout << bureaucrat << std::endl;
		}catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CHECK A GOOD BUREAUCRAT PROMOTION" << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 10);
			std::cout << bureaucrat << std::endl;
			bureaucrat.promotionGrade();
			std::cout << bureaucrat << std::endl;
		}catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CHECK A GOOD BUREAUCRAT DEMOTION" << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 10);
			std::cout << bureaucrat << std::endl;
			bureaucrat.demotionGrade();
			std::cout << bureaucrat << std::endl;
		}catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}