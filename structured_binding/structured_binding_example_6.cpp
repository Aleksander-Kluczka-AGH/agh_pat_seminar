// Beautiful example presented by cppreference:
// https://en.cppreference.com/w/cpp/language/structured_binding

#include <set>
#include <iostream>

struct BitFields
{
    int b : 4 {1},
        d : 4 {2},
        p : 4 {3},
        q : 4 {4};
    // C++20: default member initializer for bit-fields
};

int main()
{
    std::set<std::string> myset{"hello"};
    for(int i{2}; i; --i)
    {
        if(auto [iter, success] = myset.insert("Hello"); success)
        {
            std::cout << "Insert is successful. The value is \"" << *iter << "\".\n";
        }
        else
        {
            std::cout << "The value \"" << *iter << "\" already exists in the set.\n";
        }
    }

    {
        const auto [b, d, p, q] = BitFields{};
        std::cout << b << ' ' << d << ' ' << p << ' ' << q << '\n';
    }
    {
        const auto [b, d, p, q] = []
        {
            return BitFields{4, 3, 2, 1};
        }();  // lambda with falling initializer

        std::cout << b << ' ' << d << ' ' << p << ' ' << q << '\n';
    }
}

// output:
// Insert is successful. The value is "Hello".
// The value "Hello" already exists in the set.
// 1 2 3 4
// 4 3 2 1
