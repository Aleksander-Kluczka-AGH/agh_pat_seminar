#include <concepts>
#include <iostream>
#include <utility>

template <typename T, typename U>
concept AreSwappable = 
    std::movable<T> &&
    std::movable<U> &&
    std::convertible_to<U, T> &&
    std::convertible_to<T, U>;

template <typename T, typename U>
requires AreSwappable<T, U>
void Swap(T &a, U &b) noexcept
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    float a = 97.f;
    int b = 98;
    // std::swap(a, b);  // type mismatch
    Swap(a, b);
    std::cout << a << " " << b << std::endl;
}

// output:
// 98 97