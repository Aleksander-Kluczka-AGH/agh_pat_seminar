#include <iostream>

import dep;

int main(void) {
	DepA a;
	std::cout << &a << ", " << &a.d.r << std::endl;
	return 0;
}