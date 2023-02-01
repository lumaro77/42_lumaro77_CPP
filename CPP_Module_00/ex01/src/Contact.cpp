/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:30:39 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 07:56:49 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void):
	_isEmpty(true)
{}

Contact::Contact(const Contact &contact):
	_firstName(contact._firstName),
	_lastName(contact._lastName),
	_nickname(contact._lastName),
	_phoneNumber(contact._phoneNumber),
	_darkestSecret(contact._darkestSecret),
	_isEmpty(contact._isEmpty)
{}

Contact::~Contact(void) {}

Contact & Contact::operator=(const Contact &contact)
{
	if (this == &contact)
		return (*this); 
	this->_firstName = contact._firstName;
	this->_lastName = contact._lastName;
	this->_nickname = contact._nickname;
	this->_phoneNumber = contact._phoneNumber;
	this->_darkestSecret = contact._darkestSecret;
	this->_isEmpty = contact._isEmpty;
	return (*this);
}

void	Contact::setFirstName(const std::string &firstName)
{ this->_firstName = firstName; }

void	Contact::setLastName(const std::string &lastName)
{ this->_lastName = lastName; }

void	Contact::setNickname(const std::string &nickname)
{ this->_nickname = nickname; }

void	Contact::setPhoneNumber(const std::string &phoneNumber)
{ this->_phoneNumber = phoneNumber; }

void    Contact::setDarkestSecret(const std::string &darkestSecret)
{ this->_darkestSecret = darkestSecret; }

const std::string    &Contact::getFirstName() const
{ return (this->_firstName); }

const std::string    &Contact::getLastName() const
{ return (this->_lastName); }

const std::string    &Contact::getNickname() const
{ return (this->_nickname); }

const std::string    &Contact::getPhoneNumber() const
{ return (this->_phoneNumber); }

const std::string    &Contact::getDarkestSecret() const
{ return (this->_darkestSecret); }

void	Contact::setupContact(void)
{
	std::string infos_name[Contact::_contactFields] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};

	std::string entry;
	for (int i = 0; i < Contact::_contactFields; i++)
	{
		std::cout << infos_name[i] << " : ";
		std::getline(std::cin, entry);
		(i == 0) ? this->setFirstName(entry) : (void)0;
		(i == 1) ? this->setLastName(entry) : (void)0;
		(i == 2) ? this->setNickname(entry) : (void)0;
		(i == 3) ? this->setPhoneNumber(entry) : (void)0;
		(i == 4) ? this->setDarkestSecret(entry) : (void)0;
	}
	this->_isEmpty = false;
	this->_checkContact() ? this->clearContact() : (void)0;
	return ;
}

bool	Contact::_checkContact(void) const
{
	bool	invalid = 0;

	invalid = (invalid || this->getFirstName().empty());
	invalid = (invalid || this->getLastName().empty());
	invalid = (invalid || this->getNickname().empty());
	invalid = (invalid || this->getPhoneNumber().empty());
	invalid = (invalid || this->getDarkestSecret().empty());
	if (invalid)
		std::cout << "Error: invalid contact. Empty field." << std::endl;
	return (invalid);
}

void	Contact::printContact(void) const
{
	std::string infos_name[Contact::_contactFields] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};
	std::string infos[Contact::_contactFields] = {
		this->getFirstName(),
		this->getLastName(),
		this->getNickname(),
		this->getPhoneNumber(),
		this->getDarkestSecret()

	};
	for (int i = 0; i < Contact::_contactFields; i++)
		std::cout << infos_name[i] << " : " << infos[i] << std::endl;
	return ;
}

bool	Contact::isEmptyContact(void) const
{ return (this->_isEmpty); }

void	Contact::clearContact(void)
{
	this->_firstName.clear();
	this->_lastName.clear();
	this->_nickname.clear();
	this->_phoneNumber.clear();
	this->_darkestSecret.clear();
	this->_isEmpty = true;
	return ;
}
