export module dep:B;

class DepA;

export class DepB {
public:
	DepA &r;

	DepB(DepA &r) :
		r(r)
	{
	}
};