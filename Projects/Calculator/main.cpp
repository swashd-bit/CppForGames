#include <iostream>
#include "ConfigForCalc.hpp"

float fn; //first number
float sn; //second number
char op; // operator +, -, *, /

int main()
{
	std::cout << "Welcome" << "Press ENTER to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	calc(fn, sn, op);

	return 0;
}

void calc(float fn, float sn, char op)
{
	std::cout << "Enter first number." << std::endl;
	std::cin >> fn;

	while (std::cin.fail())
	{
		std::cout << "ERROR: I expected a number." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> fn;
	}

	std::cout << "Enter +, -, * or /." << std::endl;
	std::cin >> op;

	while (op != '+' && op != '-' && op != '*' && op != '/')
	{
		std::cout << "ERROR: I expected +, -, * or /." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> op;
	}

	std::cout << "Enter second number." << std::endl;
	std::cin >> sn;

	while (std::cin.fail())
	{
		std::cout << "ERROR: I expected a number." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> sn;
	}

	if (op == '+')
	{
		std::cout << fn << " + " << sn << " = " << fn + sn << std::endl;
	}
	else if (op == '-')
	{
		std::cout << fn << " - " << sn << " = " << fn - sn << std::endl;
	}
	else if (op == '*')
	{
		std::cout << fn << " * " << sn << " = " << fn * sn << std::endl;
	}
	else if (op == '/' && sn != 0)
	{
		std::cout << fn << " / " << sn << " = " << fn / sn << std::endl;
	}
	else if (op == '/' && sn == 0)
	{
		std::cout << "ERROR: Division by zero." << "\n" << std::endl;
		calc(fn, sn, op);
	}
	std::cout << "\n" << std::endl;
	calc(fn, sn, op);
}