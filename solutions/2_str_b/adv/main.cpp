#include <iostream>
#include <tuple>
#include <functional>

class Container
{
    public:
    Container()
    {
        this->fffffc = std::make_tuple(5.f, 4.f, 3.f, 2.f, 1.f, 'a');
    }
    std::tuple<float, float, float, float, float, char> fffffc;

    auto& get() { return this->fffffc; }
    void print()
    {
        auto& [one, two, three, four, five, six] = fffffc;
        std::cout << one << " "
                  << two << " "
                  << three << " "
                  << four << " "
                  << five << " "
                  << six << std::endl;
    }
};

int main()
{
    Container cont{};
    auto& [one, two, three, four, five, six] = cont.get();
    cont.print();
    one = 6.f;
    two = 7.f;
    three = 8.f;
    four = 9.f;
    five = 10.f;
    six = 'b';
    cont.print();
    return 0;
}
