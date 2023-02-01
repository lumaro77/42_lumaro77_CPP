/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:51:58 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:51:59 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	{
		std::cout << std::endl;
		std::cout << "CASE SHRUBBERY I" << std::endl;
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm form = ShrubberyCreationForm("DearAppleTree");
			std::cout << form << std::endl;
			Bureaucrat student = Bureaucrat("Student", 150);
			std::cout << student << std::endl;
			std::cout << "EXECUTION REJECTED BECAUSE FORM WAS NOT SIGNED" << std::endl;
			student.executeForm(form);
			std::cout << form << std::endl;
			std::cout << student << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CASE SHRUBBERY II" << std::endl;
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm form = ShrubberyCreationForm("DearAppleTree");
			std::cout << form << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Okto", 120);
			Bureaucrat student = Bureaucrat("Student", 150);
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
			std::cout << "EXECUTION REJECTED BECAUSE GRADE OF EXECUTOR" << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
			student.executeForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE SHRUBBERY III" << std::endl;
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm form = ShrubberyCreationForm("DearAppleTree");
			std::cout << form << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Okto", 120);
			Bureaucrat student = Bureaucrat("Student", 150);
			std::cout << bureaucrat << std::endl;
			std::cout << "EXECUTION ACCEPTED" << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.executeForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}

	
	{
		std::cout << std::endl;
		std::cout << "CASE ROBOTOMY I" << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm form = RobotomyRequestForm("MyNameIsHall");
			std::cout << form << std::endl;
			Bureaucrat student = Bureaucrat("Student", 80);
			std::cout << student << std::endl;
			std::cout << "EXECUTION REJECTED BECAUSE FORM WAS NOT SIGNED" << std::endl;
			student.executeForm(form);
			std::cout << form << std::endl;
			std::cout << student << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CASE ROBOTOMY II" << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm form = RobotomyRequestForm("MyNameIsHall");
			std::cout << form << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Okto", 40);
			Bureaucrat student = Bureaucrat("Student", 80);
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
			std::cout << "EXECUTION REJECTED BECAUSE GRADE OF EXECUTOR" << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
			student.executeForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE ROBOTOMY III" << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm form = RobotomyRequestForm("MyNameIsHall");
			std::cout << form << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Okto", 40);
			Bureaucrat student = Bureaucrat("Student", 80);
			std::cout << bureaucrat << std::endl;
			std::cout << "EXECUTION ACCEPTED" << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.executeForm(form);
			bureaucrat.executeForm(form);
			bureaucrat.executeForm(form);
			bureaucrat.executeForm(form);
			bureaucrat.executeForm(form);
			bureaucrat.executeForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	
	
	{
		std::cout << std::endl;
		std::cout << "CASE PRESIDENTIAL I" << std::endl;
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm form = PresidentialPardonForm("OhMyGod");
			std::cout << form << std::endl;
			Bureaucrat student = Bureaucrat("Student", 30);
			std::cout << student << std::endl;
			std::cout << "EXECUTION REJECTED BECAUSE FORM WAS NOT SIGNED" << std::endl;
			student.executeForm(form);
			std::cout << form << std::endl;
			std::cout << student << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CASE PRESIDENTIAL II" << std::endl;
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm form = PresidentialPardonForm("OhMyGod");
			std::cout << form << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Okto", 1);
			Bureaucrat student = Bureaucrat("Student", 30);
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
			std::cout << "EXECUTION REJECTED BECAUSE GRADE OF EXECUTOR" << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
			student.executeForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << student << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE PRESIDENTIAL III" << std::endl;
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm form = PresidentialPardonForm("OhMyGod");
			std::cout << form << std::endl;
			Bureaucrat bureaucrat = Bureaucrat("Okto", 1);
			Bureaucrat student = Bureaucrat("Student", 30);
			std::cout << bureaucrat << std::endl;
			std::cout << "EXECUTION ACCEPTED" << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.executeForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << err.what() << std::endl;
		}
	}
	
	return (0);
}