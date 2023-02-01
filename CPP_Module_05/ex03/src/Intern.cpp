/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:55:28 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 13:01:02 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
	return ;
}

Intern::Intern(const Intern &intern)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = intern;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
	return ;
}

Intern &Intern::operator=(const Intern &intern)
{
	std::cout << "Intern equal operator called." << std::endl;
	(void)intern;
	return (*this);
}

AForm *returnPresidentialForm(std::string target)
{   return new PresidentialPardonForm(target);  }

AForm *returnRobotomyForm(std::string target)
{	return new RobotomyRequestForm(target); }

AForm *returnShrubberyForm(std::string target)
{	return new ShrubberyCreationForm(target); }

AForm *Intern::makeForm(std::string formName, std::string formTarget) {

	AForm *(*func_ptr[Intern::_nbForms])(std::string) = {
		returnShrubberyForm, returnRobotomyForm, returnPresidentialForm };
	std::string formsTemplates[Intern::_nbForms] = {
		"shrubbery", "robotomy", "pardon"};
	for(unsigned int i = 0; i < Intern::_nbForms; i++) {
		if(!formName.compare(formsTemplates[i])) {
			std::cout << "Intern creates [" + formName + "]" << std::endl;
			return func_ptr[i](formTarget);}
	}
	throw Intern::FormNotFoundException();
}

std::ostream &operator<<(std::ostream &ostream, Intern const &intern)
{
	(void)intern;
	ostream << "My name is Intern....";
	ostream << "And I will have my vengeance, in this life or the next!";
	ostream << std::endl;
	return (ostream);
}

const char *Intern::FormNotFoundException::what() const throw()
{ return ("Form not found - Intern - FormNotFoundException"); }
