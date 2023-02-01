/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:18 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:13:07 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		virtual ~HumanA(void);
		HumanA(const HumanA &humanA);
		HumanA &operator=(const HumanA &humanA);

		void attack(void) const;
		
	private:
		HumanA(void);
		std::string _name;
		Weapon		*_weapon;
};

#endif
