/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:39:42 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/12 20:06:43 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) {

{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
}

{
	int ia = 2;
	int ib = 3;

	double da = 2.71828;
	double db = 3.14159;

	std::string sa = "Okto";
	std::string sb = "Student";

	std::cout << "int a = " << ia << ", int b = " << ib << std::endl;
	std::cout << "swap( int a, int b )" << std::endl;
	swap( ia, ib ); 
	std::cout << "int a = " << ia << ", int b = " << ib << std::endl;
	std::cout << "min( int a, int b ) = " << min( ia, ib ) << std::endl;
	std::cout << "max( int a, int b ) = " << max( ia, ib ) << std::endl;
	std::cout << std::endl;

	std::cout << "double a = " << da << ", double b = " << db << std::endl;
	std::cout << "swap( double a, double b )" << std::endl;
	swap( da, db ); 
	std::cout << "double a = " << da << ", double b = " << db << std::endl;
	std::cout << "min( double a, double b ) = " << min( da, db ) << std::endl;
	std::cout << "max( double a, double b ) = " << max( da, db ) << std::endl;
	std::cout << std::endl;

	std::cout << "string a = " << sa << ", string b = " << sb << std::endl;
	std::cout << "swap( string a, string b )" << std::endl;
	::swap( sa, sb ); 
	std::cout << "string a = " << sa << ", string b = " << sb << std::endl;
	std::cout << "min( string a, string b ) = " << ::min( sa, sb ) << std::endl;
	std::cout << "max( string a, string b ) = " << ::max( sa, sb ) << std::endl;
	std::cout << std::endl;
}
	return (0);
}