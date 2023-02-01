/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:47:25 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 20:55:29 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <ICharacter.hpp>

class ICharacter;

class AMateria
{
	public:
		AMateria(const std::string &type);
		virtual ~AMateria(void);
		AMateria(const AMateria &amateria);
		AMateria &operator=(const AMateria &amateria);
				
		const std::string &getType(void) const;
		
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);

	protected:
		AMateria(void);
		
		std::string _type;
};

#endif
