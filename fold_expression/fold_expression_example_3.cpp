#include <iostream>

template <typename... Typepack>
void print(Typepack&& ...args)
{
    unsigned count = 0u;
    auto func = [&count](auto&& some_arg)
    {
        std::cout << "Argument " << ++count << ": " << some_arg << std::endl;
    };

    (func(std::forward<Typepack>(args)), ...);
    // remember to forward args if they are just passed through
}

int main()
{
    print(5, 4.f, 'c', 2.0);
    return 0;
}

// output:
// Argument 1: 5
// Argument 2: 4
// Argument 3: c
// Argument 4: 2
