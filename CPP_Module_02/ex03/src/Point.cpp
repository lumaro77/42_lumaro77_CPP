/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 < lmartin2@student.42bcn.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:47:20 by lmartin2          #+#    #+#             */
/*   Updated: 2022/12/15 16:25:50 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): 
	_x(Fixed(0)),
	_y(Fixed(0))
{}

Point::~Point(void)
{}

Point::Point(const Point &point):
	_x(point._x),
	_y(point._y)
{}

Point::Point(const float x, const float y):
	_x(Fixed(x)),
	_y(Fixed(y))
{}

Point &Point::operator=(Point &point)
{
	this->~Point();
	new(this) Point(point._x.toFloat(), point._y.toFloat());
	return (*this);
}

Fixed Point::getX(void) const
{ return (this->_x); }

Fixed Point::getY(void) const
{ return (this->_y); }

std::ostream &operator<<( std::ostream &out, const Point &point )
{
	out << point.getX() << " " << point.getY();
	return (out);
}