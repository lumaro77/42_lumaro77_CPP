/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:47:11 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 10:04:15 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		virtual ~Point(void);
		Point(const Point &point);
		Point(const float x, const float y);
		Point &operator=(Point &point);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
	};

	std::ostream &operator<<( std::ostream &out, const Point &point );

	bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif