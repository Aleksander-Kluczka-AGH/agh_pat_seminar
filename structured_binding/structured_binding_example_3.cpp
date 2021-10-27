#include <iostream>
#include <tuple>

const auto foo()
{
    return std::make_pair(1, 2.f);
}

int main()
{
    // assigning values returned by a function
    auto &&[x, y] = foo();
    std::cout << x << " " << y << std::endl;
}

// output:
// 1 2
