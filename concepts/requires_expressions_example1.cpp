#include <concepts>
#include <iostream>

template <typename T>
requires requires(T input)  // implicit concept constraint, requires-expression
{
    { std::to_string(input) };  // constraint 1: std::to_string(input) is a valid expression and compiles
    { input + "anything" };  // constraint 2: input + "anything" is a valid expression and compiles
}  // all constraints have to be satisfied
std::string to_string_3(const T &text)
{
    return std::to_string(text) + " is also acceptable";
}

int main()
{
    std::cout << to_string_3(6) << std::endl;  // std::to_string(6) is a valid expression
    // first constraint for 6 is satisfied, second as well thanks to implicit cast to char

    std::cout << to_string_3('b') << std::endl;  // 'b' + "anything" is a valid expression
    // second constraint for 'b' is satisfied and then 'b' is implicitly casted to int

    // std::cout << print_string_3(6.f) << std::endl;  // constraint 2 unsatisfied and can't implicitly cast to char
    // std::cout << print_string_3("c") << std::endl;  // both constraints unsatisfied
}

// output:
// 5 is acceptable
// 98 is acceptable