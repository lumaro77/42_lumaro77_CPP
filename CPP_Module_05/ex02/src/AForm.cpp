/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:51:36 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:51:37 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):
	_name("Unknown"),
	_signed(false),
	_signGrade(AForm::_minGrade),
	_executeGrade(AForm::_minGrade)
{
	std::cout << this->_name << " AForm default constructor called." << std::endl;
	return ;
}

AForm::AForm(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExecute):
	_name(name),
	_signed(false),
	_signGrade(gradeSign),
	_executeGrade(gradeExecute)
{
	std::cout << this->_name << " AForm named constructor called." << std::endl;
	if (gradeSign > AForm::_minGrade || gradeExecute > AForm::_minGrade)
		throw AForm::GradeTooLowException();
	if (gradeSign < AForm::_maxGrade || gradeExecute < AForm::_maxGrade)
		throw AForm::GradeTooHighException();
	return ;
}

AForm::~AForm(void)
{
	std::cout << this->_name << " AForm default destructor called." << std::endl;
	return ;
}

AForm::AForm(const AForm &form):
	_name(form._name),
	_signGrade(form._signGrade),
	_executeGrade(form._executeGrade)
{
	std::cout << this->_name << " Form copy constructor called." << std::endl;
	*this = form;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << this->_name << " AForm equal operator called." << std::endl;
	this->_signed = other.getSigned();
	return *this;
}

std::string AForm::getName(void) const
{ return this->_name; }

bool AForm::getSigned(void) const
{ return this->_signed; }

unsigned int AForm::getSignGrade(void) const
{ return this->_signGrade; }

unsigned int AForm::getExecuteGrade(void) const
{ return this->_executeGrade; }

const char *AForm::GradeTooHighException::what() const throw()
{ return ("Grade is too high - Form - GradeTooHighException"); }

const char *AForm::GradeTooLowException::what() const throw()
{ return ("Grade is too low - Form - GradeTooLowException"); }

const char *AForm::AlreadySignedException::what() const throw()
{ return ("The form is already signed - Form - AlreadySignedException"); }

const char *AForm::NotSignedException::what() const throw()
{ return ("The form is not signed - Form - NotSignedException"); }

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	if (this->_signed == true)
		throw AForm::AlreadySignedException();
	else
		this->_signed = true;
	return ;
}

std::ostream &operator<< (std::ostream& ostream, const AForm& aform)
{
	ostream << "Name: " << aform.getName();
	ostream << ", Signed: " << aform.getSigned(); 
	ostream << ", Grade to Sign: " << aform.getSignGrade();
	ostream << ", Grade to Execute: " << aform.getExecuteGrade();
	ostream << std::endl;
	return (ostream);
}