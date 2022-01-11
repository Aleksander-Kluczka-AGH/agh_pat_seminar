#include <iostream>

template <typename... Pack>
void print(Pack&& ...args)
{
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

int main()
{
    print('a', 5, "ble", 4.5f);
    return 0;
}
