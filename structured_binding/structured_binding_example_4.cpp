#include <iostream>
#include <map>

int main()
{
    std::map<std::string, uint16_t> m;

    m["<A>"] = 'a';
    m["<D>"] = 'd';
    m["<S>"] = 's';
    m["<W>"] = 'w';
    m["<SPACE>"] = ' ';

    std::cout << "All keybindings:" << std::endl;
    for(auto &[name, key] : m)
    {
        std::cout << "Key " << key << " is represented by " << name << std::endl;
    }
}

// output:
// All keybindings:
// Key 97 is represented by <A>
// Key 100 is represented by <D>
// Key 115 is represented by <S>
// Key 32 is represented by <SPACE>
// Key 119 is represented by <W>
