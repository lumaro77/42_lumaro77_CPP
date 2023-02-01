/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:25:08 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/08 12:07:39 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        virtual ~Dog(void);
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);

        Brain *getBrain(void) const;
        
        void makeSound(void) const;

    private:
        Brain *_brain_dog;
};

#endif