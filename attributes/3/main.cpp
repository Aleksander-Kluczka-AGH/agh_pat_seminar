#include <cstdio>

static void check_value(size_t v)
{
	if (v > 0xFFFF) [[unlikely]] {
		std::printf("That's HUGE!");
	}
	else if (v > 0xFF) [[likely]] {
		std::printf("That's rather average!");
	}
	else [[unlikely]] {
		std::printf("You kidding me?");
	}
}

int main(void)
{
	check_value(52);
	return 0;
}