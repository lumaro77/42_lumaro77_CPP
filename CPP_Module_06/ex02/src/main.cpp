/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:56 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/13 13:58:26 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Base.hpp"

int main(void)
{
	Base* type = generate();

	identify(type);
	identify(*type);

	if (type != NULL)
		delete type;

	return (0);
}
