#include <iostream>
#include <tuple>

template <typename T>
void print(T&& arg)
{
    std::cout << arg << std::endl;
}

template <typename Fun, typename... Typepack>
void execute(Fun func, Typepack&& ...types)
{
    ( func(std::forward<Typepack>(types)), ... );
}

int main()
{
    // execute(print, "okay", 1, 3.f, 3u, 7.0);  // will not work...
    // ...because signature of function "print" can't be resolved during compilation
    // (template argument deduction failed)

    execute([](auto && args){ print(args); }, "okay", 1, 3.f, 3u, 7.0);
    // lambda can be resolved during compilation
}

// output:
// okay
// 1
// 3
// 3
// 7