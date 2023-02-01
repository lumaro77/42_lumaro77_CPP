/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:42:45 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/17 15:30:45 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    public:
        Brain(void);
        virtual ~Brain(void);
        Brain(const Brain &brain);
        Brain &operator=(const Brain &brain);
    
        std::string getIdeas(const unsigned int index) const;
        void setIdeas(std::string idea);

        void showIdeas(void) const;

    private:
        static const unsigned int _maxIdeas = 100;
        
        std::string _ideas[_maxIdeas];
        unsigned int _numStoredIdeas;
};

#endif
