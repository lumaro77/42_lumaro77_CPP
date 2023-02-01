/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:39:47 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/13 14:04:04 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
    return ;
}

template <typename T> 
const T &min(const T &x, const T &y)
{ return (x < y ? x : y); }

template <typename T> 
const T &max(const T &x, const T &y)
{ 	return (x > y ? x : y); }

# endif
