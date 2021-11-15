#include "some_bad_api.hpp"

int main(void)
{
	// we get a nice warning
	some_deprecated_function();
	return 0;
}