/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:54:52 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:57:01 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	_name("Default"),
	_grade(Bureaucrat::_minGrade)
{
	std::cout << this->_name << " Bureaucrat default constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade): 
	_name(name),
	_grade(grade)
{
	std::cout << this->_name << " Bureaucrat named default constructor called." << std::endl;
	if (grade > Bureaucrat::_minGrade)
		throw Bureaucrat::GradeTooLowException();
	if (grade < Bureaucrat::_maxGrade)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->_name << " Bureaucrat destructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat):
	_name(bureaucrat._name)
{
	std::cout << this->_name << " Bureaucrat copy constructor called." << std::endl;
	*this = bureaucrat;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << this->_name << " Bureaucrat equal operator called." << std::endl;
	this->_grade = bureaucrat._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{ return (this->_name); }

unsigned int	Bureaucrat::getGrade(void) const
{ return (this->_grade); }

void	Bureaucrat::demotionGrade(void)
{
	std::cout << this->_name << " Bureaucrat demotionGrade service called." << std::endl;
	if (this->_grade == Bureaucrat::_minGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	return ;
}

void	Bureaucrat::promotionGrade(void)
{
	std::cout << this->_name << " Bureaucrat promotionGrade service called." << std::endl;
	if (this->_grade == Bureaucrat::_maxGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	return ;
}

void Bureaucrat::signForm(AForm &aform)
{
	try {
		aform.beSigned(*this);
		std::cout << this->_name << " signed " << aform.getName() << std::endl;
	} catch	(const std::exception &e) {
		std::cerr << this->_name << " couldn't sign " << aform.getName();
		std::cerr << " because " << e.what() << std::endl;	
	}
	return ;
}

void Bureaucrat::executeForm(const AForm &aform)
{
	try {
		aform.execute(*this);
		std::cout << this->_name << " execute " << aform.getName() << std::endl;
	} catch	(const std::exception &e) {
		std::cerr << this->_name << " couldn't execute " << aform.getName();
		std::cerr << " because " << e.what() << std::endl;	
	}
	return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{ return ("Grade is too high - Bureaucrat - GradeTooHighException"); }

const char *Bureaucrat::GradeTooLowException::what() const throw()
{ return ("Grade is too low - Bureaucrat - GradeTooLowException" ); }

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrate grade " << bureaucrat.getGrade();
	return (ostream);
}
