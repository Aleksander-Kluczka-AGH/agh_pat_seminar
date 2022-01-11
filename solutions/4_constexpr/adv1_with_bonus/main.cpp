#include <iostream>

template <typename T, size_t N>
consteval auto sort(const T (&arr)[N])
{
	struct {
		T data[N];
	} res{};
	auto r = res.data;
	for (size_t i = 0; i < N; i++)
		r[i] = arr[i];
	bool has_swapped;
	do {
		has_swapped = false;
		for (size_t i = 0; i < (N - 1); i++)
			if (r[i] > r[i + 1]) {
				auto b = r[i];
				r[i] = r[i + 1];
				r[i + 1] = b;
				has_swapped = true;
			}
	} while (has_swapped);
	return res;
}

template <typename T, size_t N>
consteval bool is_sorted(const T (&arr)[N])
{
	for (size_t i = 0; i < (N - 1); i++)
		if (arr[i] > arr[i + 1])
			return false;
	return true;
}

template <typename T, size_t N>
consteval size_t arr_size(T (&arr)[N])
{
	return N;
}

int main(void)
{
	constexpr int arr[] {
		25, 2, 7, -32, 19, 3, -69, 420
	};

	constexpr auto is_init_sorted = is_sorted(arr);
	std::cout << "is_init_sorted: " << is_init_sorted << std::endl;

	constexpr auto sorted = sort(arr);
	auto sep = "";
	for (size_t i = 0; i < arr_size(sorted.data); i++) {
		std::cout << sep << sorted.data[i];
		sep = ", ";
	}
	std::cout << std::endl;

	constexpr auto is_final_sorted = is_sorted(sorted.data);
	std::cout << "is_final_sorted: " << is_final_sorted << std::endl;
	return 0;
}