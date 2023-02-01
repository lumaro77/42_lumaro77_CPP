/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:08:23 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:13:25 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		virtual ~Weapon(void);
		Weapon(const Weapon &weapon);
		Weapon &operator=(const Weapon &weapon);

		const std::string &getType(void) const;
		void setType(std::string type);
		
	private:
		Weapon(void);
		std::string _type;
};

#endif