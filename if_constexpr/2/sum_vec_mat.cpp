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
static auto sum(T &&v)
{
	double res = 0.0;
	if constexpr (T::depth == 1) {
		for (size_t i = 0; i < T::w; i++)
			res += v.data[i];
	} else if constexpr (T::depth == 2) {
		for (size_t i = 0; i < T::h; i++)
			for (size_t j = 0; j < T::w; j++)
				res += v.data[i][j];
	}
	return res;
}

int main(void)
{
	// prints s1: 10
	std::printf("s1: %g\n", sum(Mat{{{1, 2}, {3, 4}}}));
	// prints s1: 3
	std::printf("s2: %g\n", sum(Vec{{1, 2}}));
	return 0;
}