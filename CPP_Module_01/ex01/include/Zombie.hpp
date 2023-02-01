/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:36:57 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:12:03 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie(void);
		virtual ~Zombie(void);
		Zombie(const Zombie &zombie);
		Zombie &operator=(const Zombie &zombie);
		
		void setName(const std::string &name);
		
		void announce(void);

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif