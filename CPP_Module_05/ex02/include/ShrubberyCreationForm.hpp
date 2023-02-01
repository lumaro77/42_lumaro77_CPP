/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:51:13 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:51:14 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);

		const std::string getTarget() const;
		
		void execute(const Bureaucrat &executor) const;

	private:
		static const unsigned int _shrubberySignatureLevel = 145;
		static const unsigned int _shrubberyExecuteLevel = 137;
		
		std::string _target;
};

std::ostream &operator<<(std::ostream &ostream, const ShrubberyCreationForm &shrubberyCreationForm);

#endif