#include <iostream>
#include <type_traits>

template <typename T>
std::enable_if_t<std::is_same<std::string, T>::value, std::string> to_string(const T &text)
{
    return text + " is acceptible";
}

template <typename T>
std::enable_if_t<
    std::is_same<std::string, T>::value ||
    std::is_convertible<T, std::string>::value, std::string> to_string2(const T &text)
{
    return static_cast<std::string>(text) + " is also acceptable";
}

int main()
{
    std::cout << to_string(std::string("5")) << std::endl;
    std::cout << to_string2("6") << std::endl;
}

// output:
// 5 is acceptable
// 6 is also acceptable
