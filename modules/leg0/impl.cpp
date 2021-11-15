#include "header.hpp"	// ensure no mismatch on building impl

void some_proc(int arg0, double arg1)
{
	double acc = 0.0;
	for (int i = 0; i < arg0; i++)
		acc *= arg1 * i;
	some_gvar += static_cast<int>(acc);
}

int some_gvar = 0;