/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:26:18 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/08 12:05:30 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        virtual ~Cat(void);
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);

        void makeSound(void) const;
};

#endif
