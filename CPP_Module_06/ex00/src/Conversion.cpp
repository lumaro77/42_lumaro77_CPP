/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:20:31 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 13:19:35 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(void):
	_value("")
{
	std::cout << "Conversion default constructor called." << std::endl;
	return ;
}

Conversion::Conversion(const std::string &value):
	_value(value)
{
	std::cout << "Conversion valued constructor called." << std::endl;
	return ;
}

Conversion::Conversion(const Conversion &conversion)
{
	std::cout << "Conversion copy constructor called." << std::endl;
	*this = conversion;
	return ;
}

Conversion::~Conversion(void)
{
	std::cout << "Conversion destructor called." << std::endl;
	return ;
}

Conversion	&Conversion::operator=(const Conversion &conversion)
{
	std::cout << "Conversion assignation operator called." << std::endl;
	(void)conversion;
	return (*this) ;
}

void Conversion::convert(void) const
{
	bool (*func_list[Conversion::_numTypes])(const std::string &) = {&is_char, &is_int, &is_float, &is_double};

	for (unsigned int i = 0; i < Conversion::_numTypes; i++)
		if ((*func_list[i])(this->_value))
			return ;
		std::cout << "conversion impossible" << std::endl;
	return ;
}

bool is_char(std::string const &input)
{
	char char_type = 0;

	std::istringstream ss(input);
	if (ss >> char_type)
		if ((isdigit(char_type) == false && isprint(char_type)))
			if (ss.rdbuf()->in_avail() == 0) {
				cast(char_type);
				return (true); }
	return (false);
}

bool is_int(std::string const &input)
{
	int int_type = 0;

	std::istringstream ss(input);
	if (ss >> int_type )
		if (ss.rdbuf()->in_avail() == 0) {
			cast(int_type);
			return (true); }
	return (false);
}

bool is_float(std::string const &input)
{
	float floatType = 0.0f;
	bool fflagInfNan = false;
	std::string inputCopy = input;
	
	if (checkLimitSpecial(input, floatType, fflagInfNan)) {
		cast(floatType, fflagInfNan);
		return (true); }
	if (inputCopy.back() == 'f') {
		inputCopy.pop_back();
		std::istringstream ss(inputCopy);
		if (ss >> floatType) {
			if (ss.rdbuf()->in_avail() == 0) {
			 cast(floatType, fflagInfNan);
				return (true); }}}
	return (false);
}

bool is_double(std::string const &input)
{
	double doubleType = 0.0;
	bool fflagInfNan = false;

	std::istringstream ss(input);
	if (checkLimitSpecial(input, doubleType, fflagInfNan)) {
		cast(doubleType, fflagInfNan);
		return (true); }
	if (input.find(".") != std::string::npos)
		if (ss >> doubleType && ss.rdbuf()->in_avail() == 0) {
			cast(doubleType, fflagInfNan);
			return (true); } 
	return (false);
}

bool checkLimitSpecial(std::string const &input, float &floatType, bool &flagInffNanff)
{
	flagInffNanff = 1;
	if (input == "inff" || input == "+inff") {
		floatType = std::numeric_limits<float>::infinity();
		return (true); }
	if (input == "-inff") {
		floatType = -std::numeric_limits<float>::infinity();
		return (true); }
	if (input == "nanf") {
		floatType = std::numeric_limits<float>::signaling_NaN();
		return (true); }
	flagInffNanff = 0;
	return (false);
}

bool checkLimitSpecial(std::string const &input, double &doubleType, bool &fflagInfNan)
{
	fflagInfNan = 1;
	if (input == "inf" || input == "+inf") {
		doubleType = std::numeric_limits<double>::infinity();
		return (true); }
	if (input == "-inf") {
		doubleType = -std::numeric_limits<double>::infinity();
		return (true); }
	if (input == "nan") {
		doubleType = std::numeric_limits<double>::signaling_NaN();
		return (true); }
	fflagInfNan = 0;
	return (false);
}

void cast(char &char_type)
{
	printChar(static_cast<char>(char_type), 0);
	printInt(static_cast<int>(char_type), 0);
	printFloat(static_cast<float>(char_type));
	printDouble(static_cast<double>(char_type));
	return ;
}

void cast(int &int_type)
{
	printChar(static_cast<char>(int_type), 0);
	printInt(static_cast<int>(int_type), 0);
	printFloat(static_cast<float>(int_type));
	printDouble(static_cast<double>(int_type));
	return ;
}

void cast(float &floatType, bool fflagInfNan)
{
	printChar(static_cast<char>(floatType), fflagInfNan);
	printInt(static_cast<int>(floatType), fflagInfNan);
	printFloat(static_cast<float>(floatType));
	printDouble(static_cast<double>(floatType));
	return ;
}

void cast(double& doubleType, bool fflagInfNan)
{
	printChar(static_cast<char>(doubleType), fflagInfNan);
	printInt(static_cast<int>(doubleType), fflagInfNan);
	printFloat(static_cast<float>(doubleType));
	printDouble(static_cast<double>(doubleType));
	return ;
}

void printChar(char c_val, bool fflagInfNan)
{
	if (fflagInfNan == true)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c_val) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c_val << "'" << std::endl;
	return ;
}

void printInt(int int_val, bool fflagInfNan)
{
	if (fflagInfNan == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << int_val << std::endl;
	return ;
}

void printFloat(float f_val)
{
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << f_val << "f" << std::endl;
	return ;
}

void printDouble(double d_val)
{
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << d_val << std::endl;
	return ;
}
