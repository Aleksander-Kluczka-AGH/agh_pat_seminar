#include <iostream>

template <typename... Pack>
void print(Pack&& ...args)
{
    auto lambda = [](const auto& arg)
    {
        std::cout << "--" << arg << "--\n";
    };

    int count = 1;
    auto counting = [&count, &lambda](const auto& arg)
    {
        std::cout << count++ << ") ";
        lambda(arg);
    };

    (counting(std::forward<Pack>(args)), ...);
}

int main()
{
    print('a', 5, "ble", 4.5f);
    return 0;
}
 
