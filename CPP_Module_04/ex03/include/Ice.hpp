/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:35:15 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 21:03:59 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <AMateria.hpp>

class Ice: public AMateria
{
	public:
		Ice(void);
		virtual ~Ice(void);
		Ice(const Ice &ice);
		Ice &operator=(const Ice &ice);

		Ice *clone(void) const;
		void use(ICharacter &target);
};

#endif
