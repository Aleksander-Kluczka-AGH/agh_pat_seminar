#include <concepts>
#include <vector>
#include <iostream>

// we don't have to write our own concept, because theres is already
// a predefined one from STL when using above syntax (my mistake, sorry!)
// but if you still want to write one:

// template <typename T>
// concept allowIfIntegral = std::same_as<T, int> || std::same_as<T, unsigned>;

template <typename T>
class Wrapper
{
    public:
    template <std::integral U = T>
    void size();
};

template <typename T>
template <std::integral U>
void Wrapper<T>::size()
{
    std::cout << "Integral type" << std::endl;
}

int main()
{
    Wrapper<int> i;
    i.size();

    // Wrapper<std::string> s;
    // s.size();  // compilation error: constraint not satisfied
    return 0;
}
