/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:50:35 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:49:59 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		virtual ~FragTrap(void);
		FragTrap(const FragTrap &fragTrap);
		FragTrap &operator=(const FragTrap &fragTrap);
		
		void highFivesGuys(void) const;

	private:
		int _checkEnergyPoints(void) const;
		int _checkHitPoints(void) const;
	
	protected:
		unsigned int _initHitPoints() const;
		unsigned int _initEnergyPoints() const;
		unsigned int _initAttackPoints() const;
};

#endif