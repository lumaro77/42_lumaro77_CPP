/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:49 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:04:02 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		virtual ~Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const; 
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int n); //Postincrement
		Fixed operator--(int n); //Postdecrement

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		int	 getRawBits(void) const;
		void setRawBits(int const raw);

		int	  toInt(void) const;
		float toFloat(void) const;

		static Fixed min (Fixed &num1, Fixed &num2);
		static const Fixed min (const Fixed &num1, const Fixed &num2);
		static Fixed max (Fixed &num1, Fixed &num2);
		static const Fixed max (const Fixed &num1, const Fixed &num2);
		
	private:
	    int	_value;
		static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif