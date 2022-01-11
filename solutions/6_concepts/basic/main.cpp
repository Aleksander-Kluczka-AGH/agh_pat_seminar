#include <concepts>
#include <iostream>

class Owner { public: int member = 4; };

template <typename T>
concept hasMember = requires (T t)
{
    t.member;
};

template <typename T>
requires hasMember<T>
void print(const T& t)
{
    std::cout << t.member << std::endl;
}

int main()
{
    Owner own{};
    print(own);

    // double wrong = 3.0;
    // print(wrong);  // does not compile
    return 0;
}
