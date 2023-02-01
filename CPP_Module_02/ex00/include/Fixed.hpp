/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:49 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:02:48 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		virtual ~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(Fixed &fixed);

		int	 getRawBits(void) const;
		void setRawBits(int const raw);
		
	private:
	    int	_value;
		static const int _bits = 8;
};

#endif