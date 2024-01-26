#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define RED "\033[31;1m"
#define GREEN "\033[32;1m"
#define YELLOW "\033[33;1m"
#define BLUE "\033[34;1m"
#define MAGENTA "\033[35;1m"
#define CYAN "\033[36;1m"
#define WHITE "\033[37;1m"
#define END_COLOR "\033[0m"

#define MAX_VAL 750

int main()
{
	Array<int> empty;
	Array<int> const cArr(3);
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	Array<int> tmp = numbers; // copy by operator =
	Array<int> test(tmp); // copy by assignation

	//CHECK if mirror and numbers, tmp and test stocked the same value:
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i] || tmp[i] != test[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	//TRY CATCH accessing different values
	try
	{
		std::cout << GREEN << "(TRY) ACCESING empty[0]" << END_COLOR << std::endl;
		empty[0] = 0;
		std::cout << YELLOW << " (This line will not be printed if there is an exception!) " << END_COLOR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "(CATCH)" << END_COLOR << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << GREEN << "(TRY) ACCESING const cArr[1] readonly" << END_COLOR << std::endl;
		std::cout << cArr[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "(CATCH)" << END_COLOR << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << GREEN << "(TRY) ACCESING NUMBERS[-2]" << END_COLOR << std::endl;
		numbers[-2] = 0;
		std::cout << YELLOW << " (This line will not be printed if there is an exception!) " << END_COLOR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "(CATCH)" << END_COLOR << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << GREEN << "ACCESING NUMBERS[MAX_VAL]" << END_COLOR << std::endl;
		std::cout << numbers[MAX_VAL] << std::endl;
		std::cout << YELLOW << " (This line will not be printed if there is an exception!) " << END_COLOR << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "(CATCH)" << END_COLOR << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << GREEN << "ACCESING all created arrays at [0]" << END_COLOR << std::endl;
		std::cout << numbers[MAX_VAL - MAX_VAL] << std::endl;
		std::cout << mirror[MAX_VAL - MAX_VAL] << std::endl;
		std::cout << tmp[MAX_VAL - MAX_VAL] << std::endl;
		std::cout << test[MAX_VAL - MAX_VAL] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "(CATCH)" << END_COLOR << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << GREEN << "ACCESING all created arrays at [MAX_VAL - 10]" << END_COLOR << std::endl;
		std::cout << numbers[MAX_VAL - 10] << std::endl;
		std::cout << mirror[MAX_VAL - 10] << std::endl;
		std::cout << tmp[MAX_VAL - 10] << std::endl;
		std::cout << test[MAX_VAL - 10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "(CATCH)" << END_COLOR << std::endl;
		std::cerr << e.what() << '\n';
	}

	delete [] mirror;
	return 0;
}
