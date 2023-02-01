/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 < lmartin2@student.42bcn.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:34:53 by lmartin2          #+#    #+#             */
/*   Updated: 2022/12/15 16:27:59 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point A(-1, -1);
	Point B(0, 1);
	Point C(1, -1);
	
	Point i1(0, 0);
	Point i2(0, 0.5);
	Point i3(0, -0.5);
	Point i4(0.25, 0);
	Point i5(-0.25, 0);
	Point i6(0.25, -0.25);
	Point i7(-0.25, 0.25);
		
	Point o1(10, 10);
	Point o2(-10, -10);
	Point o3(10, -10);
	Point o4(-10, 10);
	Point o5(0, 10);
	Point o6(0, -10);
	Point o7(10, 0);
	Point o8(-10, 0);

	Point b1(0.5, 0);
	Point b2(-0.5, 0);
	Point b3(0, -1);
	Point b4(0.5, 0);
	Point b5(-0.5, 0);
	
	Point ei1(0.49, 0);
	Point ei2(-0.49, 0);
	Point ei3(0, -.99);
	
	Point eo1(0.4999, 0);
	Point eo2(-0.4999, 0);
	Point eo3(0, -.9999);

	std::cout << "Inner points" << std::endl;
	std::cout << "Point i1 is "<<(bsp(A, B, C, i1) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point i2 is "<<(bsp(A, B, C, i2) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point i3 is "<<(bsp(A, B, C, i3) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point i4 is "<<(bsp(A, B, C, i4) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point i5 is "<<(bsp(A, B, C, i5) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point i6 is "<<(bsp(A, B, C, i6) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point i7 is "<<(bsp(A, B, C, i7) ? "IN" : "OUT") << std::endl;	
	
	std::cout << "Outter points" << std::endl;
	std::cout << "Point o1 is "<<(bsp(A, B, C, o1) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point o2 is "<<(bsp(A, B, C, o2) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point o3 is "<<(bsp(A, B, C, o3) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point o4 is "<<(bsp(A, B, C, o4) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point o5 is "<<(bsp(A, B, C, o5) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point o6 is "<<(bsp(A, B, C, o6) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point o7 is "<<(bsp(A, B, C, o7) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point o8 is "<<(bsp(A, B, C, o8) ? "IN" : "OUT") << std::endl;

	std::cout << "Vertex out points" << std::endl;
	std::cout << "Point A is "<<(bsp(A, B, C, A) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point B is "<<(bsp(A, B, C, B) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point C is "<<(bsp(A, B, C, C) ? "IN" : "OUT") << std::endl;	
	
	std::cout << "Bisection out points" << std::endl;
	std::cout << "Point b1 is "<<(bsp(A, B, C, b1) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point b2 is "<<(bsp(A, B, C, b2) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point b3 is "<<(bsp(A, B, C, b3) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point b4 is "<<(bsp(A, B, C, b4) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point b5 is "<<(bsp(A, B, C, b5) ? "IN" : "OUT") << std::endl;	

	std::cout << "Epsilon in points" << std::endl;
	std::cout << "Point ei1 is "<<(bsp(A, B, C, ei1) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point ei2 is "<<(bsp(A, B, C, ei2) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point ei3 is "<<(bsp(A, B, C, ei3) ? "IN" : "OUT") << std::endl;

	std::cout << "Epsilon out points" << std::endl;
	std::cout << "Point eo1 is "<<(bsp(A, B, C, eo1) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point eo2 is "<<(bsp(A, B, C, eo2) ? "IN" : "OUT") << std::endl;	
	std::cout << "Point eo3 is "<<(bsp(A, B, C, eo3) ? "IN" : "OUT") << std::endl;	

	return (0);
}