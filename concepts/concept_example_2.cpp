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
requires std::integral<T> || std::floating_point<T>  // requires-clause
class Vector2
{
    public:
    T x;
    T y;
};

template <typename T>
concept IsPrintableVector = requires(T value)  // requires-expression
{
    { value.x };  // T has a member called x
    { value.y };  // T has a member called y
    { Printable<decltype(value.x)> };  // .x satisfies Printable concept
    { Printable<decltype(value.y)> };  // .y satisfies Printable concept
};

template <typename T>
requires IsPrintableVector<T>  // requires-clause
void print(const T &vec)
{
    std::cout << vec.x << " " << vec.y << std::endl;
}

int main()
{
    // print(5);  // int does not have .x and .y members
    Vector2<int> v;
    v.x = 1;
    v.y = 2;
    print(v);
}

// output:
// 1 2
