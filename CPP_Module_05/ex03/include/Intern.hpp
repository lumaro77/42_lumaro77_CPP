/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:54:08 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:59:24 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &intern);
		virtual ~Intern(void);
		Intern &operator=(const Intern &intern);

		AForm *makeForm(std::string formName, std::string formTarget);

		class FormNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw(); };
	private:
		static const unsigned int _nbForms = 3;
};

std::ostream &operator<<(std::ostream &ostream, Intern const &intern);

#endif