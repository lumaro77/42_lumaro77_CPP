/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:54:46 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:54:47 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm_Unknown", \
	ShrubberyCreationForm::_shrubberySignatureLevel, \
	ShrubberyCreationForm::_shrubberyExecuteLevel),
	_target("Unknown")
{
	std::cout << this->_target << " ShrubberyCreationForm named constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm("ShrubberyCreationForm_" + target, \
	ShrubberyCreationForm::_shrubberySignatureLevel, \
	ShrubberyCreationForm::_shrubberyExecuteLevel),
	_target(target)
{
	std::cout << this->_target << " ShrubberyCreationForm named constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm):
	AForm(shrubberyCreationForm),
	_target(shrubberyCreationForm._target)
{
	std::cout << this->_target << " ShrubberyCreationForm copy constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << this->_target << " ShrubberyCreationForm destructor called." << std::endl;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	std::cout << this->_target << " ShrubberyCreationForm assignation operator called." << std::endl;
	this->_target = shrubberyCreationForm._target;
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget(void) const
{ return (this->_target); }

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try {
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		else if (executor.getGrade() > this->getExecuteGrade())
			throw Bureaucrat::GradeTooLowException();
		else {
			std::ofstream file;
			file.open((this->_target + "_shrubbery").c_str());
			file << "	  /\\	  " << std::endl;
			file << "	 /  \\	 " << std::endl;
			file << "	/	\\	" << std::endl;
			file << "   /	  \\   " << std::endl;
			file << "  /		\\  " << std::endl;
			file << " /		  \\ " << std::endl;
			file << "--------------" << std::endl;
			file << "	  /\\	  " << std::endl;
			file << "	 /  \\	 " << std::endl;
			file << "	/	\\	" << std::endl;
			file << "   /	  \\   " << std::endl;
			file << "  /		\\  " << std::endl;
			file << " /		  \\ " << std::endl;
			file << "--------------" << std::endl;
			file << "	  /\\	  " << std::endl;
			file << "	 /  \\	 " << std::endl;
			file << "	/	\\	" << std::endl;
			file << "   /	  \\   " << std::endl;
			file << "  /		\\  " << std::endl;
			file << " /		  \\ " << std::endl;
			file << "--------------" << std::endl;
			file << "	 ----" << std::endl;
			file << "	 ----" << std::endl;
			file << "	 ----" << std::endl;
			file << "	 ----" << std::endl;
			file << "	 ----" << std::endl;
			file << "	 ----" << std::endl;
			file.flush();
			file.close();
		}
	} catch (std::exception &e) {
		std::cerr << this->getTarget() << " is still pending ";
		std::cerr << " because " << e.what() << std::endl;
	}
	return ;
}

std::ostream &operator<<(std::ostream &ostream, const ShrubberyCreationForm &shrubberyCreationForm)
{
	ostream << "Name: " << shrubberyCreationForm.getName();
	ostream << ", Target: " << shrubberyCreationForm.getTarget(); 
	ostream << ", Signed: " << shrubberyCreationForm.getSigned(); 
	ostream << ", Grade to Sign: " << shrubberyCreationForm.getSignGrade();
	ostream << ", Grade to Execute: " << shrubberyCreationForm.getExecuteGrade();
	ostream << std::endl;
	return (ostream);
}