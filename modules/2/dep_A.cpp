export module dep:A;

import :B;

export class DepA {
public:
	DepB d;

	DepA(void) :
		d(*this)
	{
	}
};