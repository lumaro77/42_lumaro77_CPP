/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:44:02 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:47:50 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):
	_name("Unknown"),
	_signed(false),
	_signGrade(Form::_minGrade),
	_executeGrade(Form::_minGrade)
{
	std::cout << this->_name << " Form default constructor called." << std::endl;
	return ;
}

Form::Form(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExecute):
	_name(name),
	_signed(false),
	_signGrade(gradeSign),
	_executeGrade(gradeExecute)
{
	std::cout << this->_name << " Form named constructor called." << std::endl;
	if (gradeSign > Form::_minGrade || gradeExecute > Form::_minGrade)
		throw Form::GradeTooLowException();
	if (gradeSign < Form::_maxGrade || gradeExecute < Form::_maxGrade)
		throw Form::GradeTooHighException();
	return ;
}

Form::~Form(void)
{
	std::cout << this->_name << " Form default destructor called." << std::endl;
	return ;
}

Form::Form(const Form &form):
	_name(form._name),
	_signGrade(form._signGrade),
	_executeGrade(form._executeGrade)
{
	std::cout << this->_name << " Form copy constructor called." << std::endl;
	*this = form;
}

Form &Form::operator=(const Form &other)
{
	std::cout << this->_name << " Form equal operator called." << std::endl;
	this->_signed = other.getSigned();
	return *this;
}

std::string Form::getName(void) const
{ return this->_name; }

bool Form::getSigned(void) const
{ return this->_signed; }

unsigned int Form::getSignGrade(void) const
{ return this->_signGrade; }

unsigned int Form::getExecuteGrade(void) const
{ return this->_executeGrade; }

const char *Form::GradeTooHighException::what() const throw()
{ return ("Grade is too high - Form - GradeTooHighException"); }

const char *Form::GradeTooLowException::what() const throw()
{ return ("Grade is too low - Form - GradeTooLowException"); }

const char *Form::AlreadySignedException::what() const throw()
{ return ("The form is already signed - Form - AlreadySignedException"); }

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	if (this->_signed == true)
		throw Form::AlreadySignedException();
	else
		this->_signed = true;
	return ;
}

std::ostream &operator<< (std::ostream& ostream, const Form& form) 
{
	ostream << "Name: " << form.getName();
	ostream << ", Signed: " << form.getSigned(); 
	ostream << ", Grade to Sign: " << form.getSignGrade();
	ostream << ", Grade to Execute: " << form.getExecuteGrade();
	ostream << std::endl;
	return (ostream);
}