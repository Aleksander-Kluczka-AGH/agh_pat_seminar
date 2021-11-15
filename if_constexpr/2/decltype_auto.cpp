#include <math.h>
#include <cstdio>

struct Vec {
	static constexpr size_t depth = 1, w = 2;
	double data[w];
};

struct Mat {
	static constexpr size_t depth = 2, w = 2, h = 2;
	double data[w][h];
};

template <typename T>
static decltype(auto) black_magic(T &&v)
{
	if constexpr (T::depth == 1) {
		// vector: will return T&&
		// universal reference: either & or &&
		return static_cast<T&&>(v);
	} else if constexpr (T::depth == 2) {
		// matrix: will return double (plain value)
		return v.data[0][0];
	} else
		return v.unknown_primitive;
}

int main(void)
{
	// prints b1: 2
	std::printf("b1: %zu\n", black_magic(Vec{{1, 2}}).w);
	// prints b2: 1
	std::printf("b2: %g\n", black_magic(Mat{{{1, 2}, {3, 4}}}));
	return 0;
}