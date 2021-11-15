#include <concepts>
#include <vector>
#include <map>
#include <iostream>

template <typename T>
concept BeginEnd = requires (T t)
{
    { t.begin() };
    { t.end() };
    { t.rbegin() };
    { t.rend() };
};

template <typename T>
concept Iterator = requires (T t)
{
    { typename T::iterator() };
    { typename T::reverse_iterator() };
    { typename T::const_iterator() };
    { typename T::const_reverse_iterator() };
};

template <typename T>
concept IsArray = requires (T t)
{
    { t[0] };
};

template <typename T>
concept IsAssociative = requires (T t)
{
    { typename T::key_type() };
    { typename T::mapped_type() };
};

template <typename T>
concept Ranged = BeginEnd<T> || Iterator<T> || IsArray<T>;

template <typename T>
requires Ranged<T> /*&& (!IsAssociative<T>)*/  // additional negation is not necessary...
// ... because compiler chooses more strict constraints first
void print_range(const T &range)
{
    for(auto &iter : range)
    {
        std::cout << iter << " ";
    }
    std::cout << std::endl;
}

template <typename T>
requires Ranged<T> && IsAssociative<T>
void print_range(const T &map_range)
{
    for(auto &[key, value] : map_range)
    {
        std::cout << "{" << key << " : " << value << "} ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vi = { 1, 2, 3, 4, 5 };
    print_range(vi);

    int ai[] = { 3, 4, 5, 6, 7 };
    print_range(ai);
    
    std::map<std::string, int> msi = { {"one", 1}, {"two", 2} };
    print_range(msi);
}

// output:
// 1 2 3 4 5
// 3 4 5 6 7
// {one : 1} {two : 2}
