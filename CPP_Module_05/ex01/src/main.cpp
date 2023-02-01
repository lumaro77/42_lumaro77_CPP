/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:48:22 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:49:06 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	{
		std::cout << std::endl;
		std::cout << "CHECK FORM CLASS" << std::endl;
		std::cout << std::endl;
		Form form_0 = Form();
		std::cout << form_0 << std::endl;
		Form form_1 = Form("Form", 15, 15);
		std::cout << form_1 << std::endl;
		Form form_2 = Form(form_1);
		std::cout << form_2 << std::endl;
		form_2 = form_0;
		std::cout << form_2 << std::endl;
	}
	
	{
		std::cout << std::endl;
		std::cout << "CHECK FORM LOW EXCEPTION" << std::endl;
		std::cout << std::endl;
		try {
			std::cout  << "Should throw a low exception:" << std::endl;
			Form form = Form("Form", 151, 150);
			std::cout << form << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout  << "Should throw a low exception:" << std::endl;
			Form form = Form("Form", 150, 151);
			std::cout << form << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
				try {
			std::cout  << "Should throw a low exception:" << std::endl;
			Form form = Form("Form", 151, 151);
			std::cout << form << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << "CHECK FORM HIGH EXCEPTION" << std::endl;
		std::cout << std::endl;
		try{
			std::cout  << "Should throw a high exception:" << std::endl;
			Form form = Form("Form", 0, 0);
			std::cout << form << std::endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		try{
			std::cout  << "Should throw a high exception:" << std::endl;
			Form form = Form("Form", 0, 1);
			std::cout << form << std::endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
				try{
			std::cout  << "Should throw a high exception:" << std::endl;
			Form form = Form("Form", 1, 0);
			std::cout << form << std::endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	
	{
		std::cout << std::endl;
		std::cout << "CHECK FORM SIGNATURE" << std::endl;
		std::cout << std::endl;
		
		{
			Form form = Form("Form", 10, 10);
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 10);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			form.beSigned(bureaucrat);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << std::endl;
		}
		
		{
			Form form = Form("Form", 20, 20);
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 10);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			form.beSigned(bureaucrat);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << std::endl;
		}
		
		try{
			Form form = Form("Form", 10, 10);
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 20);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout  << "Should throw a low exception:" << std::endl;
			form.beSigned(bureaucrat);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
			std::cout << std::endl;
		}
		
	}

	{
		std::cout << std::endl;
		std::cout << "CHECK BUREAUCRAT FORM SIGNATURE" << std::endl;
		std::cout << std::endl;
		
		{
			Form form = Form("Form", 10, 10);
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 10);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << std::endl;
		}
		
		{
			Form form = Form("Form", 5, 5);
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 10);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << std::endl;
		}
		
		{
			Form form = Form("Form", 10, 10);
			Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 10);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			bureaucrat.signForm(form);
			std::cout << form << std::endl;
			std::cout << bureaucrat << std::endl;
			std::cout << std::endl;
		}
		
	}
	
	return (0);
}