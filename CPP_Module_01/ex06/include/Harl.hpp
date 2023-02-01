/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:14:03 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:45:37 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
    public:
		Harl();
		~Harl();

		void complain(std::string level);

	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};

#endif