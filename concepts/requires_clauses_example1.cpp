#include <concepts>
#include <iostream>

template <typename T>
requires std::same_as<T, std::string>  // requires-clause
std::string to_string(const T &text)
{
    return text + " is acceptable";
}

template <typename T>
requires std::same_as<T, std::string> ||
    std::convertible_to<T, std::string>  // requires-clause
std::string to_string_2(const T &text)
{
    return static_cast<std::string>(text) + " is acceptable";
}

int main()
{
    std::cout << to_string(std::string("5")) << std::endl;
    // std::cout << to_string("Error") << std::endl;  // char[5] != std::string
    std::cout << to_string_2("This") << std::endl;  // char[5] is convertible to std::string
}

// output:
// 5 is acceptable
// This is acceptable
