#include "some_bad_api.hpp"

int main(void)
{
	// compiler can't tell something terrible
	// is about to happen!
	some_deprecated_function();
	return 0;
}