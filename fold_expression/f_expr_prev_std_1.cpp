#include <iostream>

// #1
// declaration of a helper class template accepting parameter packs
template <typename... Typepack>
class PrintHelper;

// #2
// template specialization: "unfolding" template pack by taking the first parameter
// and recursively passing through the rest of the parameter pack
template <typename First, typename... Rest>
class PrintHelper<First, Rest...>
{
    public: static constexpr void print(const First& first, const Rest& ...rest)
    {
        std::cout << first << " ";
        PrintHelper<Rest...>::print(rest...);
    }
};

// #3
// template specialization: the whole pack has been unfolded but the last type
// still remains
template <typename Last>
class PrintHelper<Last>
{
    public: static constexpr void print(const Last& last)
    {
        std::cout << last << std::endl;
    }
};

// #4
// the actual function used to print out parameter pack
template <typename... Typepack>
constexpr void print(const Typepack& ...vars)
{
    PrintHelper<Typepack...>::print(vars...);
}

int main()
{
    print(5, 4.f, 'c', 2.0, "hello there");
    return 0;
}

// order of calls (for 3 parameters):
// 4 > 1 > 2 > 1 > 2 > 1 > 3

// output: 
// 5 4 c 2 hello there
