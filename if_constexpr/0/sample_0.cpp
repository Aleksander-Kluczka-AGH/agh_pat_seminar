
// compile-time evaluable
3 * 5 & 2

// can yield compile-time value (if n is known)
constexpr size_t fib(size_t n)
{
	...
}

// compile-time evaluable given right above fib
3 * fib(6 - 2)

// cannot yield compile-time value
size_t fib(size_t n)
{
	...
}

// n must be compile-time known
consteval size_t fib(size_t n)
{
	...
}

// valid given right above fib
constexpr auto fib_res = 3 * fib(6 - 2);