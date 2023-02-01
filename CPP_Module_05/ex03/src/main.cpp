/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:55:18 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:55:19 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{

	{
		std::cout << std::endl;
		std::cout << "CASE NON VALID " << std::endl;
		std::cout << std::endl;
		try {
			Intern intern;
			Bureaucrat bureaucrat("Okto", 120);
			AForm *aform = NULL;
			std::cout << intern << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << "WILL FAIL WHEN CREATE" << std::endl;
			aform = intern.makeForm("42", "42");
			if (aform)
				std::cout << *aform << std::endl;
			if (aform)
				delete aform;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CASE SHRUBBERY " << std::endl;
		std::cout << std::endl;
		try {
			Intern intern;
			Bureaucrat bureaucrat("Okto", 120);
			AForm *aform = NULL;
			std::cout << intern << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << "WILL CREATE SHRUBBERY" << std::endl;
			aform = intern.makeForm("shrubbery", "Shrubbery");
			std::cout << *aform << std::endl;
			aform->beSigned(bureaucrat);
			std::cout << "WILL PLANT A TREE" << std::endl;
			bureaucrat.executeForm(*aform);
			delete aform;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CASE ROBOTOMY " << std::endl;
		std::cout << std::endl;
		try {
			Intern intern;
			Bureaucrat bureaucrat("Okto", 40);
			AForm *aform = NULL;
			std::cout << intern << std::endl;
			std::cout << bureaucrat << std::endl;		
			std::cout << "WILL CREATE ROBOTOMY" << std::endl;
			aform = intern.makeForm("robotomy", "Robotomy");
			std::cout << *aform << std::endl;
			aform->beSigned(bureaucrat);
			std::cout << "WILL DRILL AND DO ROBOTOMY" << std::endl;
			bureaucrat.executeForm(*aform);
			delete aform;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CASE PRESIDENTIAL PARDON " << std::endl;
		std::cout << std::endl;
		try {
			Intern intern;
			Bureaucrat bureaucrat("Okto", 3);
			AForm *aform = NULL;
			
			std::cout << "WILL CREATE PRESIDENTIAL PARDON" << std::endl;
			aform = intern.makeForm("pardon", "Pardon");
			std::cout << *aform << std::endl;
			aform->beSigned(bureaucrat);
			std::cout << "WILL HAVE PARDON" << std::endl;
			bureaucrat.executeForm(*aform);
			delete aform;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}