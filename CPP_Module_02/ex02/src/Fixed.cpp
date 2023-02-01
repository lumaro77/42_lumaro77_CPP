/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 < lmartin2@student.42bcn.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:53 by lmartin2          #+#    #+#             */
/*   Updated: 2022/12/15 11:55:33 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): 
	_value(0)
{}

Fixed::Fixed(int n):
	_value(n << Fixed::_bits)
{}

Fixed::Fixed(const float f):
	_value((int)roundf(f * (1 << Fixed::_bits)))
{}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed &fixed):
	_value(fixed._value)
{}

Fixed & Fixed::operator=(const Fixed &fixed)
{
	this->_value = fixed._value;
	return (*this);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{ return (Fixed(fixed.toFloat() + this->toFloat())); }

Fixed Fixed::operator-(const Fixed &fixed) const
{ return (Fixed(fixed.toFloat() - this->toFloat())); }

Fixed Fixed::operator*(const Fixed &fixed) const
{ return (Fixed(fixed.toFloat() * this->toFloat())); }

Fixed Fixed::operator/(const Fixed &fixed) const
{ return (Fixed(fixed.toFloat() / this->toFloat())); }

bool	Fixed::operator>(const Fixed &fixed) const
{ return (this->toFloat() > fixed.toFloat()); }

bool	Fixed::operator<(const Fixed &fixed) const
{ return (this->toFloat() < fixed.toFloat()); }

bool	Fixed::operator>=(const Fixed &fixed) const
{ return (this->toFloat() >= fixed.toFloat()); }

bool	Fixed::operator<=(const Fixed &fixed) const
{ return (this->toFloat() <= fixed.toFloat()); }

bool	Fixed::operator==(const Fixed &fixed) const
{ return (this->toFloat() == fixed.toFloat()); }

bool	Fixed::operator!=(const Fixed &fixed) const
{ return (this->toFloat() != fixed.toFloat()); }

Fixed Fixed::operator++() {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed fixed(*this);
	operator++();
	return (fixed);
}

Fixed Fixed::operator--() {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed fixed(*this);
	operator--();
	return (fixed);
}

int	Fixed::getRawBits(void) const
{ return (this->_value); }

void Fixed::setRawBits(int raw)
{ this->_value = raw; }

int	Fixed::toInt(void) const
{ return (this->_value >> Fixed::_bits); }

float Fixed::toFloat(void) const
{ return((float)this->_value / (float)(1 << Fixed::_bits)); }

Fixed Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

Fixed const Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if ((Fixed)num1 < (Fixed)num2)
		return num1;
	return num2;
}

Fixed Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

Fixed const Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if ((Fixed)num1 > (Fixed)num2)
		return num1;
	return num2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
