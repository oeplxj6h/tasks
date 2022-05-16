#include <iostream>
#include <fstream>
#include <string>

int ad(int o1, int o2)
{
	return o1 > o2 ? o1 - o2 : o2 - o1;
};

int main(int argc, char* argv[])
{
	std::ifstream in;
	bool a;
	int* nums, * test;
	unsigned long long l[2] = { 0, 1 }, cycle[2], m, c;

	in.open(argv[1], std::ios::in);

	if (in.is_open())
	{
		while (in >> c)
			l[0]++;

		in.close();

		nums = new int[l[0]];
		test = new int[l[0]];
		cycle[0] = 0;

		in.open(argv[1], std::ios::in);

		while (in >> nums[cycle[0]])
			cycle[0]++;

		in.close();
	}
	else
	{
		std::cout << "Could not open file '" << argv[1] << "'" << std::endl;

		return 0;
	};

	test[0] = nums[0];

	for (cycle[0] = 1; cycle[0] < l[0]; cycle[0]++)
	{
		a = true;

		for (cycle[1] = 0; cycle[1] < l[1]; cycle[1]++)
			if (test[cycle[1]] == nums[cycle[0]])
			{
				a = false;

				break;
			};

		if (a)
		{
			test[l[1]] = nums[cycle[0]];

			l[1]++;
		};
	};

	m = 0;
	for (cycle[0] = 0; cycle[0] < l[0]; cycle[0]++)
		m += ad(test[0], nums[cycle[0]]);

	for (cycle[0] = 1; cycle[0] < l[1]; cycle[0]++)
	{
		c = 0;

		for (cycle[1] = 0; cycle[1] < l[0]; cycle[1]++)
			c += ad(test[cycle[0]], nums[cycle[1]]);

		if (c < m)
			m = c;
	};

	delete[] test;
	delete[] nums;

	std::cout << m;

	return 0;
}