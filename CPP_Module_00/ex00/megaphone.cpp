/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:10:16 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/15 07:05:17 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}else{
		int i = 0;
		std::string str;
		while (++i < argc)
			str.append(argv[i]);
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str << std::endl; }
	return (0);
}