#include <iostream>

template <bool IsString>
auto proc(void)
{
	if constexpr (IsString)
		return "Some string!";
	else
		return 3.14;

}

int main(void)
{
	std::cout << proc<true>() << std::endl;	// prints "Some string!"
	std::cout << proc<false>() << std::endl;	// prints "3.14"
	return 0;
}