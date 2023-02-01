/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:38:11 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 19:28:42 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
	public:
		Span(const unsigned int size);
		Span(const Span &span);
		virtual ~Span(void);
		Span &operator=(const Span &span);

		void addNumber(const int number);
		void addNumber(std::vector<int>::const_iterator itBegin, \
						std::vector<int>::const_iterator itEnd);
		unsigned int longestSpan(void);
		unsigned int shortestSpan(void);

		class FullException: public std::exception{
			public:
				char const *what() const throw() {
					return ("Full"); }};
					
		class NoSpanException: public std::exception{
			public:
				char const *what() const throw() {
					return ("No span"); }};

	private:
		Span(void);
		
		unsigned int		_size;
		std::vector<int>	_container;
};

#endif