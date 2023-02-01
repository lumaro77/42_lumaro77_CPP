/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:53:45 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 13:03:21 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		virtual ~AForm(void);
		AForm &operator=(const AForm &form);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecuteGrade(void) const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException: public std::exception{
			public:
				virtual const char *what() const throw(); };

		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw(); };

		class AlreadySignedException: public std::exception{
			public:
				virtual const char *what () const throw (); };

		class NotSignedException: public std::exception{
			public:
				virtual const char *what () const throw (); };

	protected:
		AForm(void);
		AForm(const std::string &name, const unsigned int gradeSign, const unsigned int gradeExecute);
		AForm(const AForm &form);
	
	private:
		static const unsigned int _maxGrade = 1;
		static const unsigned int _minGrade = 150;
		
		const std::string   _name;
		bool				_signed;
		const unsigned int  _signGrade;
		const unsigned int  _executeGrade;
};

std::ostream &operator<< (std::ostream &ostream, const AForm &form);

#endif 