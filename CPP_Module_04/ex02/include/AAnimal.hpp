/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:07:32 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/10 10:40:14 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
    public:
        virtual ~AAnimal(void);
        AAnimal &operator=(const AAnimal &animal);

        std::string getType(void) const;
        
        virtual void makeSound(void) const = 0;
        
    protected:
        AAnimal(void);
        AAnimal(const std::string &type);
        AAnimal(const AAnimal &animal);
        
        std::string _type;
};

#endif
    