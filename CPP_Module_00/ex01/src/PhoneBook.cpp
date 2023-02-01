/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 10:54:41 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 07:57:54 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::startPhoneBook(void)
{
    std::cout << "Welcome to your phonebook !" << std::endl;
    std::cout << std::endl;
	std::cout << "Available entries are :" << std::endl;
    std::cout << "ADD" << std::endl;
    std::cout << "SEARCH" << std::endl;
    std::cout << "EXIT" << std::endl;

    int state = 0;
    while (true)
    {
        if (state == 0)
            state = this->_menuPhoneBook();
        else if (state == 1)
            state = this->_addPhoneBook();
        else if (state == 2)
            state = this->_searchPhoneBook();
        else if (state == 3)
            this->_endPhoneBook();
    }
    return ; 
}

int PhoneBook::_menuPhoneBook(void)
{
    std::string entry;
    
	std::cout << std::endl;
	std::cout << "So, how may I help you? > ";
	std::getline(std::cin, entry);
	if (std::cin.eof())
		return (3);
	if (!entry.compare("ADD"))
		return (1);
	if (!entry.compare("SEARCH"))
		return (2);
	if (!entry.compare("EXIT"))
		return (3);
	std::cout << "Input is discarded.";
	std::cout << std::endl;
	return (0);
}

int PhoneBook::_addPhoneBook(void)
{
    int j = 0;
    while (!this->_list[j].isEmptyContact() && j < PhoneBook::_contactSize)
        j++;
	if (j == PhoneBook::_contactSize)
        return (_fullPhoneBook());
    this->_list[j].setupContact();
    return (0);
}

int	PhoneBook::_fullPhoneBook()
{
	std::string line;

	std::cout << "Contact list is full,  the oldest one will be removed.";
	std::cout << std::endl;
    while (true){
		std::cout << "Shall I continue? [yes - no] : ";
        
		std::getline(std::cin, line);
		if (std::cin.eof() || !line.compare("no")){
            std::cout << "Back to the menu." << std::endl;
			return (0);
        }else if (!line.compare("yes")){
            for (int i = 1; i < PhoneBook::_contactSize ; i++)
                this->_list[i - 1] = this->_list[i];
            this->_list[(PhoneBook::_contactSize - 1)].clearContact();
			return (1);
		}else{
			std::cout << "Input is discarded.";
			std::cout << std::endl;
		}
    }
    return (0);
}

int PhoneBook::_searchPhoneBook(void) const
{
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    int j = 0;
    while (!this->_list[j].isEmptyContact() && j < PhoneBook::_contactSize){
        std::cout << "         " << j << "|";
        _formatPrintPhoneBook(this->_list[j].getFirstName());
        std::cout << "|";
        _formatPrintPhoneBook(this->_list[j].getLastName());
        std::cout << "|";
        _formatPrintPhoneBook(this->_list[j].getNickname());
        std::cout << std::endl;
        j++;
    }
    if (j > 0 && _printByIndexPhoneBook(j) == 0){
		std::cout << "Input is discarded. Return to the main menu." << std::endl;
	}   
	return (0);
}

int PhoneBook::_printByIndexPhoneBook(int contactIndex) const
{
    std::string entry;
    
    std::cout << "Choose an index between 0 and " << contactIndex - 1 << " : ";
    std::getline(std::cin, entry);
    if (entry.length() != 1)
        return (0);
    int index = atoi(entry.c_str());
    if (index < 0 || index > PhoneBook::_contactSize || this->_list[index].isEmptyContact())
        return (0);
    this->_list[index].printContact();
    return (1);
}

void PhoneBook::_formatPrintPhoneBook(std::string s)
{
    if (s.size() > 10){
        s = s.insert(9, ".");
        s = s.substr(0, 10);
    }else{
        while (s.length() < 10)
            s = s.insert(0, " ");
	}   
	std::cout << s;
    return ;
}

void PhoneBook::_endPhoneBook(void)
{
    std::cout << std::endl;
    std::cout << "Contacts are lost forever! Bye!" << std::endl;
    exit(0);
}

int main(void)
{
    PhoneBook phonebook;
    
    phonebook.startPhoneBook();
    return (0);
}
