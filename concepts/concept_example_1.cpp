#include <concepts>
#include <iostream>

template <typename T>
concept Printable =
    std::integral<T> ||
    std::floating_point<T> ||
    std::same_as<T, std::string> ||
    std::convertible_to<T, std::string>;
// any of the above constraints has to be satisfied

template <typename T>
requires Printable<T>  // requires-clause
void print(const T &input)
{
    std::cout << input << std::endl;
}

int main()
{
    print(5);
    print(10.f);
    print("b");
    print('a');
}

// output:
// 5
// 10
// b
// a
