/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:39:47 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/12 20:48:37 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		//Constructors an destructor
		Array<T>(void):
			_array(NULL),
			_n(0)
		{
			std::cout << "Array<T> default constructor called." << std::endl;
			return ;
		}

		Array<T>(unsigned int n):
			_array(new T[n]()),
			_n(n)
		{
			std::cout << "Array<T> constructor overload (n in param) called." << std::endl;
			return ;
		}

		~Array<T>(void)
		{
			std::cout << "Array<T> destructor called." << std::endl;
			if (this->_array)
				delete[] this->_array;
			return ;
		}

		Array<T>(const Array<T> &array):
			_array(NULL),
			_n(0)
		{
			std::cout << "Array<T> copy constructor called." << std::endl;
			*this = array;
			return ;
		}
		
		//Operator overload
		Array<T> &operator=(const Array<T> &rhs)
		{
			std::cout << "Array<T> assignation operator called." << std::endl;
			if (this != &rhs)
			{
				this->_n = rhs._n;
				if (this->_array) {
					delete[] this->_array;
					this->_array = NULL; }
				if (rhs._array)
					this->_array = new T[rhs._n];
				for (unsigned int i = 0; i < this->_n; i++)
					this->_array[i] = rhs._array[i];
			}
			return (*this);
		}

		bool operator==(const Array<T> &rhs)
		{
			if (this->size() != rhs.size())
				return false;
			for (unsigned int i = 0; i < this->_n; i++)	{
				if (this->_array[i] != rhs._array[i])
					return false; }
			return (true);
		}

		T &operator[](unsigned int idx) const
		{
			if (idx >= this->_n)
				throw WrongIndex();
			else
				return this->_array[idx];
		}

		//Accessors
		unsigned int size(void) const
		{ return this->_n; }

		//Exceptions
		class WrongIndex : public std::exception {
			public:
				const char *what() const throw() {
					return "Error : wrong index!"; }
		};

	private:
		T 				*_array;
		unsigned int	_n;
};

#endif
