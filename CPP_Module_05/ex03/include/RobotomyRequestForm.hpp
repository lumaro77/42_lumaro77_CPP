/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   RobotomyRequestForm.hpp							:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lmartin2 <lmartin2@student.42bcn.com>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/11 14:00:39 by lmartin2		  #+#	#+#			 */
/*   Updated: 2023/01/15 12:35:39 by lmartin2		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);

		const std::string getTarget() const;
	
		void execute(const Bureaucrat &executor) const;
	
	private:
		static const unsigned int _robotomySignatureLevel = 72;
		static const unsigned int _robotomyExecuteLevel = 45;

		static bool _approved;

		std::string _target;
};

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &robotomyRequestForm);

#endif