/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:37:09 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 20:13:15 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

int main(void)
{

	{
		std::cout << std::endl;
		std::cout << "CASE MUTANTSTACK" << std::endl;
		std::cout << std::endl;
		
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		mstack.push(0);
		mstack.push(5);
		mstack.push(17);
		mstack.push(0);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl;
		std::cout << "CASE MUTANTSTACK" << std::endl;
		std::cout << std::endl;
		
		std::list<int> mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.push_back(0);
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.push_back(0);
		
		std::cout << mstack.back() << std::endl;
		
		mstack.pop_back();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	return (0);
}
