/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:24 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:13:36 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		virtual ~HumanB(void);
		HumanB(const HumanB &humanB);
		HumanB &operator=(const HumanB &humanB);

		void attack(void) const;
		void setWeapon(Weapon &weapon);

	private:
		HumanB(void);
		std::string _name;
		Weapon		*_weapon;
};

#endif
