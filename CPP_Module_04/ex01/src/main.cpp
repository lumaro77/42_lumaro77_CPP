/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin2 <lmartin2@student.42bcn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:06:03 by lmartin2          #+#    #+#             */
/*   Updated: 2023/01/06 18:01:30 by lmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "CASE CLASS AS ARGUMENT" << std::endl;
		std::cout << std::endl;
		
		std::cout << "Constructors : " << std::endl;	
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;

		std::cout << "Destructors : " << std::endl;
		delete j;//should not create a leak
		delete i;
		std::cout << std::endl;
	}

	{
		std::cout << "CASE PET IDEA" << std::endl;
		
		std::cout << "Constructors : " << std::endl;
		Dog dog;
		Cat cat;
		std::cout << std::endl;
		std::cout << "Dog thinks :" << std::endl;
		dog.getBrain()->setIdeas(" I love my owner!");
		dog.getBrain()->setIdeas(" I found a slipper !");
		dog.getBrain()->setIdeas(" Oh ! Another slipper ! I can steal it ! huhuhu!");
		dog.getBrain()->showIdeas();
		std::cout << "Cat thinks :" << std::endl;
		cat.getBrain()->setIdeas(" I hate my servant!");
		cat.getBrain()->setIdeas(" What will happen if i push the glass out of the table ? ");
		cat.getBrain()->setIdeas(" I think you should give me my fav food. ");
		cat.getBrain()->showIdeas();
		std::cout << std::endl;
		std::cout << "Destructors : " << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "CASE DEEP COPY" << std::endl;
		std::cout << std::endl;
	
		Dog chowchow;
		chowchow.getBrain()->setIdeas("I am a chowchow");
		Dog firulai = chowchow;
		std::cout << std::endl;
		
		std::cout << "before change : " << std::endl;
		chowchow.getBrain()->showIdeas();
		firulai.getBrain()->showIdeas();
		std::cout << std::endl;
		
		std::cout << "after change : " << std::endl;
		chowchow.getBrain()->setIdeas("Yes I am!");
		firulai.getBrain()->setIdeas("NO ! I am a firulai!");
		chowchow.getBrain()->showIdeas();
		firulai.getBrain()->showIdeas();
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "CASE WILD ARRAY" << std::endl;
		std::cout << std::endl;
		
		int n = 10;
		Animal *pets[n];
		for (int i = 0; i < n; i++)
		{

			for (i = 0; i < n / 2; i++)
			{
				std::stringstream idea;
				idea <<  "I am Dog number " << i;
				pets[i] = new Dog();
				((Dog*) pets[i])->getBrain()->setIdeas(idea.str());
			}
			while (i < n)
			{
				std::stringstream idea;
				idea <<  "I am Cat number " << i;
				pets[i] = new Cat();
				((Cat*) pets[i])->getBrain()->setIdeas(idea.str());
				i++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			std::cout << std::endl;
			pets[i]->makeSound();
			if (i < n / 2)
				((Dog*) pets[i])->getBrain()->showIdeas();
			else
				((Cat*) pets[i])->getBrain()->showIdeas();
		}
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
			delete pets[i];
	}
}