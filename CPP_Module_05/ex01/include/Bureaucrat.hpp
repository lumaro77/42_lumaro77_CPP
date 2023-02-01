/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:43:03 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 12:43:07 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <Form.hpp>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const unsigned int grade);
		virtual ~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		std::string	 getName(void) const;
		unsigned int	getGrade(void) const;

		void	promotionGrade(void);
		void	demotionGrade(void);

		void	signForm(Form &form);

		class GradeTooHighException: public std::exception{
			public:
				virtual const char *what() const throw(); };

		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw(); };

	private:
		static const unsigned int _maxGrade = 1;
		static const unsigned int _minGrade = 150;

		const std::string   _name;
		unsigned int		_grade;	
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif