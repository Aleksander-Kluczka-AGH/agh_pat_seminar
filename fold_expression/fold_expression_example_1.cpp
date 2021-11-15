#include <iostream>

static constexpr bool Type1 = true;
static constexpr bool Type2 = false;

template <typename... Typepack>
constexpr bool isTrue(const Typepack& ...args)
{
    return (args && ...);
    // return arg1 && arg2 && arg3 && arg4 ...;
}

int main()
{
    std::cout << isTrue(Type1, (1 == 1), Type2, true) << std::endl;
    std::cout << isTrue(Type1, true) << std::endl;
    std::cout << isTrue() << std::endl;  // undefined behaviour?
}

// output:
// 0
// 1
// 1 ?
