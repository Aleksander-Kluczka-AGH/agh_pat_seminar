#include <cstdio>
#include <csetjmp>

static jmp_buf jump_to;

static const char* will_unwind(void)
{
	longjmp(jump_to, 1);
	__builtin_unreachable();
	// explicitly unreachable
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
	__builtin_unreachable();
	// explicitly unreachable
	// std::printf call and return code won't be generated
	std::printf("after unwind?!\n");
	return 1;
}