/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:03 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/06 15:33:21 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "CASE VIRTUAL:" << std::endl;
		std::cout << std::endl;
		
		std::cout << "Constructors : " << std::endl;
		const Animal *pet = new Animal();
		const Animal *firulais = new Dog();
		const Animal *misi = new Cat();
		std::cout << std::endl;
		
		std::cout  << "Get type: " << std::endl;
		std::cout << firulais->getType() << " " << std::endl;
		std::cout << misi->getType() << " " << std::endl;
		std::cout << std::endl;
		
		std::cout  << "waiting for cat misi sound : " << std::endl;
		misi->makeSound(); // will output the cat sound!
		std::cout  << "waiting for dog firulais sound : " << std::endl;
		firulais->makeSound(); // will output the dog sound!
		std::cout  << "waiting for animal sound : " << std::endl;
		pet->makeSound(); // will output the animal sound!
		std::cout << std::endl;
		
		std::cout  << "Destructors : " << std::endl;
		delete pet;
		delete firulais;
		delete misi;
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE NO VIRTUAL:" << std::endl;
		std::cout << std::endl;
		
		std::cout << "Constructors : " << std::endl;
		const WrongAnimal *pet = new WrongAnimal();
		const WrongAnimal *misi = new WrongCat();
		const WrongCat *my_cat = new WrongCat();
		std::cout << std::endl;
		
		std::cout  << "Get type: " << std::endl;
		std::cout << misi->getType() << " " << std::endl;
		std::cout << std::endl;
		
		std::cout  << "wrong cat sound : " << std::endl;
		misi->makeSound(); 
		std::cout  << "wrong cat but right sound : " << std::endl;
		my_cat->makeSound(); 
		std::cout  << "waiting for animal sound : " << std::endl;
		pet->makeSound();
		std::cout << std::endl;
		
		std::cout  << "destructors : " << std::endl;
		delete pet;
		delete misi;
		delete my_cat;
	}
	
	{
		std::cout << std::endl;
		std::cout << "CASE COPY CONSTRUCT" << std::endl;
		std::cout << std::endl;
		
		std::cout << "Constructors : " << std::endl;
		Cat sisi;
		Cat tiger(sisi);
		Dog junior;
		Dog sultan (junior);
		std::cout << std::endl;
		
		std::cout << "Copying : " << std::endl;
		sisi = tiger;
		sultan = junior;
		std::cout << std::endl;
		
		std::cout  << "destructors : " << std::endl;
	}
}