/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:35:05 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:34:12 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		virtual ~MateriaSource(void);
		MateriaSource(const MateriaSource &materiaSource);
		MateriaSource &operator=(const MateriaSource &materiaSource);

		void learnMateria(AMateria *materia);
		AMateria *createMateria(const std::string &type);
	
	private:
		void _cloneMateriaArray(const MateriaSource &materiaSource);
		void _copyMateriaArray(const MateriaSource &materiaSource);
		void _clearMateriaArray(void);
		
		static const unsigned int _maxMaterials = 4;
		
		unsigned int _nbMaterials;
		AMateria *_materials[MateriaSource::_maxMaterials];		
};

#endif
