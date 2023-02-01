/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:35:20 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:33:35 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <AMateria.hpp>

class Cure: public AMateria
{
	public:
		Cure(void);
		virtual ~Cure(void);
		Cure(const Cure &cure);
		Cure &operator=(const Cure &cure);
	
		Cure *clone(void) const;
		void use(ICharacter &target);
};

#endif
