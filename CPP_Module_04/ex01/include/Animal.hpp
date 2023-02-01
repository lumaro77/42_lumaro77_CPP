/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:07:32 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/06 16:52:56 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(const std::string &type);
        virtual ~Animal(void);
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);

        std::string getType(void) const;
        
        virtual void makeSound(void) const;
        
    protected:
        std::string _type;
};

#endif
    