#include <cstdio>
#include <csetjmp>

static jmp_buf jump_to;

[[noreturn]]
static const char* will_unwind(void)
{
	longjmp(jump_to, 1);
	// unreachable: longjmp is [[noreturn]] in <setjmp.h>
	// return code won't be generated, no warning issued
}

int main(void)
{
	if (setjmp(jump_to)) {
		std::printf("longjmped\n");
		return 0;
	}
	std::printf("before unwind\n");
	will_unwind();
	// unreachable: will_unwind is [[noreturn]]
	// std::printf call and return code won't be generated
	std::printf("after unwind?!\n");
	return 1;
}