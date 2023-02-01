/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:46:05 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 11:20:21 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void):
    _numStoredIdeas(0)
{
    std::cout << "Brain constructor called" << std::endl;
    for (unsigned int i = 0; i < this->_maxIdeas; i++)
        this->_ideas[i].clear();
    return ;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

Brain::Brain(const Brain &brain):
    _numStoredIdeas(brain._numStoredIdeas)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (unsigned int i = 0; i < this->_numStoredIdeas; i++)
        this->_ideas[i] = brain._ideas[i];
    return ;
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "Brain assignation operator called" << std::endl;
    this->_numStoredIdeas = brain._numStoredIdeas;
    for (unsigned int i = 0; i < this->_numStoredIdeas; i++)
        this->_ideas[i] = brain._ideas[i];
    return (*this);
}

std::string Brain::getIdeas(const unsigned int i) const
{
    if (i >= Brain::_maxIdeas)
    {
        std::cout << "Error: we do not know that idea" << std::endl;
        return ("Error: we do not know that idea");
    }else{
        std::cout << "Brain getIdeas called" << std::endl;
        return (this->_ideas[i]);
    }
}

void Brain::setIdeas(std::string idea)
{
    if (this->_numStoredIdeas == Brain::_maxIdeas) {
        std::cout << "Error: we run out of ideas" << std::endl;
    }else{
        std::cout << "Brain setIdeas called" << std::endl;
        this->_ideas[this->_numStoredIdeas] = idea;
        _numStoredIdeas++;
    }
    return ;
}

void Brain::showIdeas(void) const
{
	for (unsigned int i = 0; i < this->_numStoredIdeas; i++)
	    std::cout << this->_ideas[i] << std::endl;
    return ;
}