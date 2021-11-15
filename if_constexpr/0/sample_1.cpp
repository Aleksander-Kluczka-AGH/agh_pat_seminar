#include <cstdlib>

class Obj {
public:
	bool values[16];
};

template <bool IsAwesome, size_t SomeSize, Obj NowThatsDeep>
consteval Obj nice_templ_func(void)
{
	Obj res;
	res.values[SomeSize] = IsAwesome;
	return res;
}

constexpr auto v = nice_templ_func<true, 13, Obj{}>();

// will pass, don't worry ;)
static_assert(v.values[13] == true, "we are doomed!");