/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:25:08 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/08 12:05:34 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        virtual ~Dog(void);
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);

        void makeSound(void) const;
};

#endif