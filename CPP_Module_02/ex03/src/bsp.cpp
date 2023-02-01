/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 < lmartin2@student.42bcn.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:47:15 by lmartin2          #+#    #+#             */
/*   Updated: 2022/12/15 16:26:45 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Check if sum of PBC + PAC + PAB areas is same as ABC area. 
// Also check if P is in ABC sides or vertex.

static float area(Point const a, Point const b, Point const c) {

    float area = 0;

	area  = (a.getX() * (b.getY() - c.getY())).toFloat();
    area += (b.getX() * (c.getY() - a.getY())).toFloat();
    area += (c.getX() * (a.getY() - b.getY())).toFloat();
    area /= 2.0;
    
    return (area >= 0 ? area : -area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	const float epsilon = 0.0001;

	float abc = area(a, b, c);
	float pbc = area(point, b, c);
	float apc = area(a, point, c);
	float abp = area(a, b, point);

	if (pbc < epsilon || apc < epsilon || abp < epsilon)
		return (false);
	else
    	return ((pbc + apc + abp - abc) < epsilon);
}