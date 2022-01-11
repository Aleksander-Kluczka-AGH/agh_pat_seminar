#include <iostream>

template <typename T, T First, T...Rest>
consteval T max(void)
{
	if constexpr (sizeof...(Rest) > 0) {
		auto r = max<T, Rest...>();
		return r > First ? r : First;
	} else
		return First;
}

int main(void)
{
	constexpr auto mx = max<int, 25, 2, 7, 420, -32, 19, 3, -69>();
	std::cout << "Max: " << mx << std::endl;
	return 0;
}