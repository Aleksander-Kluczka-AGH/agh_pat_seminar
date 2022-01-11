#include <iostream>
#include <setjmp.h>

#define catch(c) if (setjmp(c._excp_jmp_buf))
#define throw(err) { _excp_err_code = err; longjmp(_excp_jmp_buf, 1); }

class Computable
{
	const char *_excp_err_code;

public:
	jmp_buf _excp_jmp_buf;

	auto get_error(void) const { return _excp_err_code; }
	size_t compute(size_t n)
	{
		size_t res = 1;
		for (size_t i = 0; i < n; i++) {
			auto prev = res;
			res *= 256;
			if (res < prev)
				throw("Result overflow");
		}
		return res;
	}
};

int main(void)
{
	Computable c;
	catch (c) {
		std::cerr << "ERROR: " << c.get_error() << std::endl;
		return 1;
	}
	std::cout << "Result: " << c.compute(14) << std::endl;
	return 0;
}