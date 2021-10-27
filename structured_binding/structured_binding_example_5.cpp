#include <iostream>

class Test
{
public:
    Test(int fi, int se) : first(fi), second(se) {}

    int first;
    int second;
};

int main()
{
    Test obj{1, 2};
    std::cout << obj.first << " " << obj.second << std::endl;

    // assigning references to values of class members
    auto &[one, two] = obj;  // members must be public
    one = 3; two = 4;
    std::cout << obj.first << " " << obj.second << std::endl;

    return 0;
}

// output:
// 1 2
// 3 4
