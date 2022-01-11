#include <setjmp.h>

[[noreturn]]
int jmp(jmp_buf &buf)
{
	longjmp(buf, 1);
}

int main(void)
{
	jmp_buf b;
	if (setjmp(b))
		return 0;
	return jmp(b);
}