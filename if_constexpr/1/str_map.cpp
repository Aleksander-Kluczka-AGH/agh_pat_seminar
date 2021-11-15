// Adapted from my C++ compiler draft at
// https://github.com/FMC64/notec/blob/master/src/Pp.cpp

#include <cstdint>

template <typename T, size_t Size>
struct carray
{
	static constexpr size_t size = Size;
	T data[Size];
};

template <size_t op, auto str, auto ...rest>
static inline consteval size_t computeStrTableSize(void)
{
	// append size of string + sizeof('\0')
	size_t s = str.size + 1;
	if constexpr (sizeof...(rest) > 0) // next string in map
		s += computeStrTableSize<rest...>();
	return s;
}

template <size_t op, auto str, auto ...rest>
static inline consteval void fillStrTable(auto &res, size_t &ndx)
{
	// copy current offset into table index
	res.data[op] = ndx;
	// copy string characters at current offset
	for (size_t i = 0; i < str.size; i++)
		res.data[ndx++] = str.data[i];
	res.data[ndx++] = 0; // insert null terminating character
	if constexpr (sizeof...(rest) > 0) // next string in map
		fillStrTable<rest...>(res, ndx);
}

template <auto ...rest>
static inline consteval auto computeStrTable(void)
{
	// we got the index and string per entry in map
	constexpr size_t entry_count = sizeof...(rest) / 2;
	// size is index size + size for all strings
	constexpr size_t size =
		entry_count + computeStrTableSize<rest...>();
	carray<char, size> res;
	// write string data right after index
	size_t off = entry_count;
	fillStrTable<rest...>(res, off);
	return res;
}

template <size_t Size>
using CStr = carray<char, Size>;

// convert string literal to CStr (constexpr size as member)
template <size_t Size>
static constexpr auto genCStr(const char (&str)[Size])
{
	CStr<Size - 1> res;	// last '\0' counts as 1
	for (size_t i = 0; i < Size - 1; i++)
		res.data[i] = str[i];
	return res;
}

#include <cstdio>

static constexpr auto op_str = computeStrTable<
#define STR_ENTRY(n, s) n, genCStr(s)
	STR_ENTRY(0, "!"),
	STR_ENTRY(1, "+"),
	STR_ENTRY(2, "-"),
	STR_ENTRY(3, "&"),
	STR_ENTRY(4, ">>="),
	STR_ENTRY(5, "*"),
	STR_ENTRY(6, ":"),
	STR_ENTRY(7, "<")
#undef STR_ENTRY
>();

int main(void)
{
	// prints table size: 26 bytes
	std::printf("table size: %zu bytes\n", op_str.size);
	// prints op: >>=
	std::printf("op: %s\n", op_str.data + op_str.data[4]);
	return 0;
}