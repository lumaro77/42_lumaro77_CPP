/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:16:04 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 09:38:51 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);	}

	std::string filename(argv[1]);
	std::string filenameOut(filename + ".replace");
	std::string s1(argv[2]);
	std::string s2(argv[3]);        

	std::string lineIn;
	std::string lineOut;
	std::ifstream ifs(filename);
	
	if (!ifs.is_open()){
		std::cout << "Error: can't open file " << filename << std::endl;
		return (1);	}
		
	std::ofstream ofs(filenameOut);
	if (!ofs.is_open()){
	std::cout << "Error: can't open file " << filenameOut << std::endl;
	return (1);}

	while (std::getline(ifs, lineIn)){
		lineOut.clear();
		for (size_t i = 0; i < lineIn.length();){
			if (lineIn.substr(i, s1.length()) == s1){
				lineOut += s2;
				lineIn = lineIn.erase((size_t)i, (size_t)s1.length());
			}else{
				lineOut += lineIn[i++];	}}
		ofs << lineOut << std::endl;}

	ifs.close();
	ofs.close();

	return (0);
}
