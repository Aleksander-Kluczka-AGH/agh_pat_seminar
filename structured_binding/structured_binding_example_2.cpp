#include <iostream>
#include <tuple>
#include <functional>  // std::ref

int main()
{
    int t[2] = {1, 2};

    std::tuple<int, int&> tu = std::make_tuple(t[0], std::ref(t[1]));
    
    auto [w, x] = tu;
    const auto [y, z] = tu;
    
    static_assert(std::is_same<decltype(w), int       >::value);
    static_assert(std::is_same<decltype(x), int&      >::value);
    static_assert(std::is_same<decltype(y), const int >::value);
    static_assert(std::is_same<decltype(z), int&      >::value);
}
