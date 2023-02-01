/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:38:11 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 19:36:23 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void):
			std::stack<T>() {}
		
		~MutantStack(void){}
		
		MutantStack(const MutantStack &mutantStack):
			std::stack<T>(mutantStack) {}
		
		MutantStack &operator=(const MutantStack &mutantStack) {
			std::stack<T>::operator=(mutantStack);
			return *this; }

		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator	begin(void){
			return std::stack<T>::c.begin(); }

		iterator	end(void){
			return std::stack<T>::c.end(); }
};