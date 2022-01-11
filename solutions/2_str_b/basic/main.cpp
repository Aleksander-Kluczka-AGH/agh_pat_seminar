#include <iostream>
#include <tuple>

int main()
{
    auto object = std::make_pair<int, int>(1, 2);
    auto [sb1, sb2] = object;
    auto rp = std::pair<int&, int&>(sb1, sb2);
    auto& [rsb1, rsb2] = rp;    // alternative, as declared variables are of underlying bound type: auto [rsb1, rsb2] = std::pair<int&, int&>(sb1, sb2);

    rsb1 = 3;
    rsb2 = 4;
    std::cout << sb1 << " " << sb2 << '\n';
    std::cout << object.first << " " << object.second << '\n';
    return 0;
}
