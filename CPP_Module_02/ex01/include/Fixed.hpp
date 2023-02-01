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

		int	 getRawBits(void) const;
		void setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
		
	private:
	    int	_value;
		static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif