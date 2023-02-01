/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:37:46 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 19:30:27 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	std::cout << "Span default constructor called" << std::endl;
	return ;
}

Span::Span(const unsigned int size):
	_size(size)
{
	std::cout << "Span valued constructor called" << std::endl;
	return ;
}

Span::Span(const Span &span)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = span;
	return ;
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
	return ;
}

Span &Span::operator=(const Span &span)
{
	std::cout << "Span assignation operator called" << std::endl;
	this->_size = span._size;
	this->_container = span._container;
	return (*this);
}

void Span::addNumber(int number)
{
	if (this->_container.size() >= this->_size)
		throw Span::FullException();
	this->_container.push_back(number);
	return ;
}

void Span::addNumber(std::vector<int>::const_iterator itBegin, \
						std::vector<int>::const_iterator itEnd )
{
    if (this->_container.size() >= this->_size)
		throw Span::FullException();
    this->_container.insert(this->_container.end(), itBegin, itEnd);
}

unsigned int Span::longestSpan(void)
{
	if (this->_container.size() < 2)
		throw Span::NoSpanException();
	int min = *std::min_element(this->_container.begin(), this->_container.end());
	int max = *std::max_element(this->_container.begin(), this->_container.end());
	unsigned int longest = static_cast<unsigned int>(max - min);
	return (longest);
}

unsigned int Span::shortestSpan(void)
{
	if (this->_container.size() < 2)
		throw Span::NoSpanException();
	unsigned int shortest = this->longestSpan();
	std::sort(this->_container.begin(), this->_container.end());
	for (std::vector<int>::iterator i = this->_container.begin(); \
			i != (this->_container.end() - 1); i++) {
		unsigned int span = static_cast<unsigned int>(*(i + 1) - *i);
		shortest = shortest > span ? span : shortest; }
	return (shortest);
}
