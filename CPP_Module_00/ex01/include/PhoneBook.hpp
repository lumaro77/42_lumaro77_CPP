/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:42:30 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 07:52:56 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
    public:
		PhoneBook(void);
		virtual ~PhoneBook(void);
		void	startPhoneBook(void);
	
	private:
		int			_addPhoneBook(void);
		int			_fullPhoneBook(void);
		int			_searchPhoneBook(void) const;
		int			_printByIndexPhoneBook(int contactIndex) const;

		static int	_menuPhoneBook(void);
		static void	_formatPrintPhoneBook(std::string s);
		static void	_endPhoneBook(void);

	
		static const int _contactSize = 8;
		Contact _list[PhoneBook::_contactSize];
};

#endif





