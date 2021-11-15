#include <concepts>
#include <string>
#include <iostream>

template <typename T>
class A
{
    template <typename U = T>
    requires std::integral<U>
    void f();
};

template <typename T>
template <typename U>
requires std::integral<U>
void A<T>::f()
{
    std::cout << "Integral type" << std::endl;
}

int main()
{
    A<int> a;
    a.f();

    A<std::string> s;
    // s.f();  // compilation error: constraint not satisfied
    return 0;
}

// output:
// Integral type
