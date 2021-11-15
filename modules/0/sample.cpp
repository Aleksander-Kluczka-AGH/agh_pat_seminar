module;

#include <cstdio>

export module sample;

const char* to_speak = "stuff\n";

export void speak(void)
{
	std::printf(to_speak);
}