/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:34:27 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 11:15:21 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal(const WrongAnimal &animal);
        WrongAnimal &operator=(const WrongAnimal &animal);

        std::string getType(void) const;
        
        void makeSound(void) const;
        
    protected:
        std::string _type;
};


#endif