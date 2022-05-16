#include <iostream>
#include <fstream>

unsigned short f(float o1, float o2)
{
	return o1 < o2 ? 1 : (o1 > o2 ? 2 : 0);
};

int main(int argc, char* argv[])
{
	std::ifstream in;
	float c[2], r, t, ** p;
	unsigned long long np = 0, cycle = 0;

	in.open(argv[1], std::ios::in);

	if (in.is_open())
	{
		in >> c[0] >> c[1] >> r;

		in.close();
	}
	else
	{
		std::cout << "Could not open file '" << argv[1] << "'" << std::endl;

		return 0;
	};

	const float rs = r * r;

	in.open(argv[2], std::ios::in);

	if (in.is_open())
	{
		while (in >> t >> t)
			np++;

		in.close();

		p = new float*[np];
		for (cycle = 0; cycle < np; cycle++)
			p[cycle] = new float[2];

		cycle = 0;

		in.open(argv[2], std::ios::in);

		while (in >> p[cycle][0] >> p[cycle][1])
			cycle++;

		in.close();
	}
	else
	{
		std::cout << "Could not open file '" << argv[2] << "'" << std::endl;

		return 0;
	};

	for (cycle = 0; cycle < np; cycle++)
		std::cout << f((p[cycle][0] - c[0]) * (p[cycle][0] - c[0]) + (p[cycle][1] - c[1]) * (p[cycle][1] - c[1]), rs) << std::endl;

	for (cycle = 0; cycle < np; cycle++)
		delete[] p[cycle];
	delete[] p;

	return 0;
}