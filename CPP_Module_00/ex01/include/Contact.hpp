/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:30:11 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 07:46:11 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    public:
		Contact(void);
		Contact(const Contact &contact);
		virtual ~Contact(void);
		Contact &operator=(const Contact &contact);

		void setFirstName(const std::string &firstName);
		void setLastName(const std::string &lastName);
		void setNickname(const std::string &nickname);
		void setPhoneNumber(const std::string &phoneNumber);
		void setDarkestSecret(const std::string &darkestSecret);

		const std::string &getFirstName() const;
		const std::string &getLastName() const;
		const std::string &getNickname() const;
		const std::string &getPhoneNumber() const;
		const std::string &getDarkestSecret() const;

		void setupContact(void);
		void printContact(void) const;
		bool isEmptyContact(void) const;
		void clearContact(void);

    private:
        bool _checkContact(void) const;
        
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        bool        _isEmpty;

        static const int _contactFields = 5;
};

#endif
