/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:43:17 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:43:19 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExecute);
		virtual ~Form(void);
		Form(const Form &form);
		Form &operator=(const Form &form);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecuteGrade(void) const;

		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception{
			public:
				virtual const char *what() const throw(); };

		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw(); };

		class AlreadySignedException: public std::exception{
			public:
				virtual const char *what () const throw (); };

	private:
		static const unsigned int _maxGrade = 1;
		static const unsigned int _minGrade = 150;
		
		const std::string   _name;
		bool				_signed;
		const unsigned int  _signGrade;
		const unsigned int  _executeGrade;
};

std::ostream &operator<< (std::ostream &ostream, const Form &form);

#endif 