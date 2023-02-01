/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:34:18 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 19:22:21 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"

int    main(void)
{

{
	std::cout << std::endl;
	std::cout << "CASE SUBJECT ELEMENTS"<< std::endl;
	std::cout << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

{
    std::cout << std::endl;
    std::cout << "CASE NO ELEMENTS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(10);
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}
    
{
    std::cout << std::endl;
    std::cout << "CASE ONE ELEMENT"<< std::endl;
    std::cout << std::endl;
    Span span = Span(10);
    try{
        span.addNumber(42);
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

{
    std::cout << std::endl;
    std::cout << "CASE TWO ELEMENTS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(10);
    try{
        span.addNumber(-2147483648);
        span.addNumber(2147483647);
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

{
    std::cout << std::endl;
    std::cout << "CASE TOO MANY ELEMENTS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(5);
    try{
        span.addNumber(17);
        span.addNumber(13);
		span.addNumber(17);
        span.addNumber(13);
		span.addNumber(17);
        span.addNumber(13);
		span.addNumber(17);
        span.addNumber(13);
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

{
    std::cout << std::endl;
    std::cout << "CASE FIVE ELEMENTS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(10);
    try{
        for (int i = 0; i < 5; i++)
			span.addNumber(2*i);
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

{
    std::cout << std::endl;
    std::cout << "CASE 100 ELEMENTS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(100);
    try{
		srand((unsigned) time(NULL));
        for (int i = 0; i < 100; i++)
			span.addNumber(rand());
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

{
    std::cout << std::endl;
    std::cout << "CASE 10 000 ELEMENTS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(10000);
    try{
		srand((unsigned) time(NULL));
        for (int i = 0; i < 10000; i++)
			span.addNumber(rand());
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

{
    std::cout << std::endl;
    std::cout << "CASE 1 000 000 ELEMENTS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(1000000);
    try{
		srand((unsigned) time(NULL));
        for (int i = 0; i < 1000000; i++)
			span.addNumber(rand());
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

{
    std::cout << std::endl;
    std::cout << "CASE 1 000 ELEMENTS BY GROUPS"<< std::endl;
    std::cout << std::endl;
    Span span = Span(1000);
	try{
		std::vector<int> data(1000);
		std::srand(time(NULL));
		std::generate(data.begin(), data.end(), std::rand);
		span.addNumber(data.begin(), data.end());
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
    try{
        std::cout << "Short span: "<< span.shortestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
   try{
        std::cout << "Long span: "<< span.longestSpan() << std::endl;
    } catch(const std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

	return (0);
}