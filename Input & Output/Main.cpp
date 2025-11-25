#include <iostream>
#include <string>
#include <limits>
#include "ConfigForIO.hpp"


int main()
{

	std::string name;
	int age;

	std::cout << "What is your name?" << std::endl;
	std::cin >> name;



	std::cout << "What is your age?" << std::endl;
	std::cin >> age;


	while (std::cin.fail())
	{
		std::cout << "ERROR: I expected a number." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> age;
	}

	if (age <= 25)
	{
		Young(name, age);
	}
	else if (age > 25 && age <= 60)
	{
		Adult(name, age);
	}
	else
	{
		Elderly(name, age);
	}

	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	
	return 0;
}

void Young(std::string name, int age)
{
	std::cout << "Hello, " << name;
	std::cout << " You are only " << age << " years old." << std::endl;
}

void Adult(std::string name, int age)
{
	std::cout << "Hello, " << name;
	std::cout << " You are already " << age << " years old." << std::endl;
}

void Elderly(std::string name, int age)
{
	std::cout << "Hello, " << name;
	std::cout << " You are very wise for your age." << std::endl;
}