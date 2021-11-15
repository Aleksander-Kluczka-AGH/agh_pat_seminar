#include <iostream>

template <typename... Typepack>
void print(Typepack&& ...args)
{
    ((std::cout << args << " "), ...);  // notice no ';' at the end of std::cout
    std::cout << std::endl;
}

int main()
{
    print(5, 4.f, 'c', 2.0, "hello there");
    return 0;
}

// output:
// 5 4 c 2 hello there
