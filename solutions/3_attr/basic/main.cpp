[[deprecated]]
void some_deprecated_function(void)
{
}

[[nodiscard]]
char* some_nodiscard_function(void)
{
	return new char[128];
}

int main(void)
{
	some_deprecated_function();

	auto a = some_nodiscard_function();	// no warning
	delete[] a;

	some_nodiscard_function();
	return 0;
}