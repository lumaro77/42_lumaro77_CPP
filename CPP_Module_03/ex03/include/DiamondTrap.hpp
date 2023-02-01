/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:33:45 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:50:03 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		virtual ~DiamondTrap(void);
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap &operator=(const DiamondTrap &diamondTrap);
	
		void attack(const std::string &target);
		void whoAmI(void) const;
		
	private:
		std::string _name;

};
#endif