#include <iostream>
#include <concepts>

template <typename... Typepack>
concept Printable = requires(Typepack&& ...type)
{
    ((std::floating_point<decltype(type)> ||
      std::integral<decltype(type)> ||
      std::convertible_to<decltype(type), std::string>), ...);
};

template <typename... Typepack>
requires Printable<Typepack...>
void print(Typepack&& ...type)
{
    ((std::cout << type << std::endl), ...);
}

class Object
{
    public: int b = 8;
    operator int() const { return b; }
};

int main()
{
    Object obj;
    std::string str = "ohno";
    print(5, 4.f, 'c', 3.0, "hello there", obj, str);
    return 0;
}
