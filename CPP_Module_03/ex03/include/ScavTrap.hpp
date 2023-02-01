/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:39:27 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:49:47 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		virtual ~ScavTrap(void);
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap& operator=(const ScavTrap &scavTrap);
		
		void guardGate() const;

	private:
		int _checkEnergyPoints(void) const;
		int _checkHitPoints(void) const;
	
	protected:
		unsigned int _initHitPoints() const;
		unsigned int _initEnergyPoints() const;
		unsigned int _initAttackPoints() const;
};

#endif
