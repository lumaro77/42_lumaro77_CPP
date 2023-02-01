/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:26:18 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/08 12:07:33 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        virtual ~Cat(void);
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);

        Brain *getBrain(void) const;

        void makeSound(void) const;
    
    private:
        Brain *_brain_cat;
};

#endif
