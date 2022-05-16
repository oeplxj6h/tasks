#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	const unsigned long long n = std::stoull(argv[1]), m = std::stoull(argv[2]), s = (m - 1) % n;

	unsigned long long p;

	std::cout << 1;

	for (p = s; p != 0; p = (p + s) % n)
		std::cout << p + 1;

	return 0;
}