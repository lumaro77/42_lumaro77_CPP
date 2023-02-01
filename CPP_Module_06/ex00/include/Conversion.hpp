/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:20:35 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 13:20:30 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <iomanip>
# include <sstream>

class Conversion
{
	public:
		Conversion(const std::string &value);
		Conversion(const Conversion &conversion);
		virtual ~Conversion(void);
		Conversion &operator=(const Conversion &conversion);

		void convert(void) const;

	private:
		static const unsigned int _numTypes = 4;
		
		Conversion(void);
		
		const std::string _value;
};

bool is_char(std::string const &input_to_parse);
bool is_int(std::string const &input_to_parse);
bool is_double(std::string const &input_to_parse);
bool is_float(std::string const &input_to_parse);

bool checkLimitSpecial(std::string const &input, float &floatType, bool &flagInffNanff);
bool checkLimitSpecial(std::string const &input, double &doubleType, bool &fflagInfNan);

void cast(char &char_type);
void cast(int &int_type);
void cast(float &floatType, bool fflagInfNan);
void cast(double& doubleType, bool fflagInfNan);

void printChar(char c_val, bool fflagInfNan);
void printInt(int i_val, bool fflagInfNan);
void printFloat(float f_val);
void printDouble(double d_val);

#endif
