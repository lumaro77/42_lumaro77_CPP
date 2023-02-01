/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:52:04 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:52:05 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm_Unknown", \
	PresidentialPardonForm::_presidentialSignatureLevel, \
	PresidentialPardonForm::_presidentialExecuteLevel),
	_target("Unknown")
{
	std::cout << this->_target << " PresidentialPardonForm named constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("PresidentialPardonForm_" + target, \
	PresidentialPardonForm::_presidentialSignatureLevel, \
	PresidentialPardonForm::_presidentialExecuteLevel),
	_target(target)
{
	std::cout << this->_target << " PresidentialPardonForm named constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
 	std::cout << this->_target << " PresidentialPardonForm destructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm):
	AForm(presidentialPardonForm),
	_target(presidentialPardonForm.getTarget())
{
	std::cout << this->_target << " PresidentialPardonForm copy constructor called." << std::endl;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
	std::cout << this->_target << " PresidentialPardonForm assignation operator called." << std::endl;
	this->_target = presidentialPardonForm.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{   return (this->_target); }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	try {
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		else if (executor.getGrade() > this->getExecuteGrade())
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} catch (std::exception &e) {
		std::cerr << this->getTarget() << " is still pending ";
		std::cerr << " because " << e.what() << std::endl;
	}
	return ;
}

std::ostream &operator<< (std::ostream& ostream, const PresidentialPardonForm &presidentialPardonForm)
{
	ostream << "Name: " << presidentialPardonForm.getName();
	ostream << ", Target: " << presidentialPardonForm.getTarget(); 
	ostream << ", Signed: " << presidentialPardonForm.getSigned(); 
	ostream << ", Grade to Sign: " << presidentialPardonForm.getSignGrade();
	ostream << ", Grade to Execute: " << presidentialPardonForm.getExecuteGrade();
	ostream << std::endl;
	return (ostream);
}