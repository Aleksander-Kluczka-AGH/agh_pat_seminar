module;

#include <iostream>

export module printer;

export void print_something(void)
{
	std::cout << "It's me!!" << std::endl;
}