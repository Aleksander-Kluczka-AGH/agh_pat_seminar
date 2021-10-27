#include <iostream>
#include <tuple>
#include <functional>  // std::ref

int main()
{
    // assigning value from an array
    int t[2] = {1, 2};
    auto [foo, bar] = t;  // the type has to be "auto"
    // creates e[2], copies t into e, then foo refers to e[0], bar refers to e[1]
    std::cout << foo << " " << bar << std::endl;

    // auto [x, y, z] = t;  // error: array of 2 ints decomposes into 2 elements

    // assigning value from pair
    auto &&[a, b] = std::make_pair(3u, 4.f);
    std::cout << a << " " << b << std::endl;

    // assigning value from tuple
    const auto &[c, d, e] = std::make_tuple("yes", "no", 5);
    std::cout << c << " " << d << " " << e << std::endl;

    // auto [f, g, h, i] = std::make_tuple(1, std::make_pair(2, 3), 4);
    // error: tuple decomposes into 3 elements
}

// output:
// 1 2
// 3 4
// yes no 5
