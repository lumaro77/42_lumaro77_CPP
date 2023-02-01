/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:50:54 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:50:55 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		virtual  ~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);
	
		std::string getTarget(void) const;
		
		void execute(const Bureaucrat &executor) const;

	private:
		static const unsigned int _presidentialSignatureLevel = 25;
		static const unsigned int _presidentialExecuteLevel = 5;
		
		std::string _target;
};

std::ostream &operator<<(std::ostream &ostream, const PresidentialPardonForm &presidentialPardonForm);

#endif