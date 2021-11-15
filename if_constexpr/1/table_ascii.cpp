// Adapted from my C++ compiler draft at
// https://github.com/FMC64/notec/blob/master/src/TokenStream.hpp

#include <cstdlib>
#include <cstdint>

struct CTable {
	static constexpr size_t size = 128;
	uint8_t data[size];
};

namespace Trait {
	static constexpr uint8_t is_digit = 0x01;
	static constexpr uint8_t is_alpha = 0x02;
	static constexpr uint8_t is_alphanum = 0x04;
	static constexpr uint8_t is_identifier = 0x08;
	static constexpr uint8_t is_identifier_first = 0x10;
}

static consteval CTable computeTraitTable(void)
{
	CTable res;
	for (uint8_t i = 0; i < res.size; i++) {
		bool is_digit = i >= '0' && i <= '9';
		bool is_alpha = (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z');
		bool is_alphanum = is_alpha || is_digit;
		bool is_identifier = is_alphanum || i == '_';
		bool is_identifier_first = is_identifier && !is_digit;
		res.data[i] = (is_digit ? Trait::is_digit : 0) |
			(is_alpha ? Trait::is_alpha : 0) |
			(is_alphanum ? Trait::is_alphanum : 0) |
			(is_identifier ? Trait::is_identifier : 0) |
			(is_identifier_first ? Trait::is_identifier_first : 0);
	}
	return res;
}

#include <cstdio>

static constexpr auto trait_table = computeTraitTable();

int main(void)
{
	// prints 0
	std::printf("%d\n", (trait_table.data['0'] & Trait::is_identifier_first) != 0);
	// prints 1
	std::printf("%x\n", (trait_table.data['_'] & Trait::is_identifier_first) != 0);
	// prints 1
	std::printf("%x\n", (trait_table.data['f'] & Trait::is_identifier) != 0);
	return 0;
}