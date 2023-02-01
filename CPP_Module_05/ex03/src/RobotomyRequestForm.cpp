/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:55:05 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:55:06 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::_approved = false;

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm_Unknown", \
	RobotomyRequestForm::_robotomySignatureLevel, \
	RobotomyRequestForm::_robotomyExecuteLevel),
	_target("Unknown")
{
	std::cout << this->_target << " RobotomyRequestForm named constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm("RobotomyRequestForm_" + target, \
	RobotomyRequestForm::_robotomySignatureLevel, \
	RobotomyRequestForm::_robotomyExecuteLevel),
	_target(target)
{
	std::cout << this->_target << " RobotomyRequestForm named constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm):
	AForm(robotomyRequestForm),
	_target(robotomyRequestForm._target)
{
	std::cout << this->_target << " RobotomyRequestForm copy constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << this->_target << " RobotomyRequestForm destructor called." << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
	std::cout << this->_target << " RobotomyRequestForm assignation operator called" << std::endl;
	_target = robotomyRequestForm._target;
	return *this;
}

const std::string RobotomyRequestForm::getTarget() const
{ return (this->_target); }

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try {
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		else if (executor.getGrade() > this->getExecuteGrade())
			throw Bureaucrat::GradeTooLowException();
		else {
			std::cout << "*DRILLING NOISES*" << std::endl;
			if (this->_approved == false) {
				this->_approved = true;
				std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
			} else {
				this->_approved = false;
				std::cout << "Robotomy failed." << std::endl;}
		}
	} catch (std::exception &e) {
		std::cerr << this->getTarget() << " is still pending ";
		std::cerr << " because " << e.what() << std::endl;
	}
	return ;
}

std::ostream &operator<<(std::ostream &ostream, const RobotomyRequestForm &robotomyRequestForm)
{
	ostream << "Name: " << robotomyRequestForm.getName();
	ostream << ", Target: " << robotomyRequestForm.getTarget(); 
	ostream << ", Signed: " << robotomyRequestForm.getSigned(); 
	ostream << ", Grade to Sign: " << robotomyRequestForm.getSignGrade();
	ostream << ", Grade to Execute: " << robotomyRequestForm.getExecuteGrade();
	ostream << std::endl;
	return (ostream);
}