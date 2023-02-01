/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:10:07 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:32:59 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	public:
		Character(const std::string &name);
		virtual ~Character(void);
		Character(const Character &character);
		Character &operator=(const Character &character);
		
		const std::string &getName(void) const;
		
		void equip(AMateria *materia);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
		
	private:
		Character(void);
		
		bool _materiaValidIndex(const int idx) const;
		void _cloneMateria(const Character &character);
		void _deleteMateria(void);
		void _cloneBin(const Character &character);
		void _deleteBin(void);
		
		static const int _maxMaterials = 4;
		static const int _maxBin = 4;

		std::string _name;
		int _nbMaterials;
		int _nbBin;
		AMateria *_materials[Character::_maxMaterials];
		AMateria *_bin[Character::_maxBin];
};

#endif
