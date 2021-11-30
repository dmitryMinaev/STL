#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	vector<int> vec;

	for (int i = 0; i < 12; i++)
		vec.push_back(-25 + rand() % 60);

	cout << "Before:\n";
	for_each(vec.begin(), vec.end(), [](int i) {cout << i << '\t'; });

	auto funcSort = [](int i, int j)
	{
		return abs(i) < abs(j);
	};

	sort(vec.begin(), vec.end(), funcSort);

	cout << "\nAfter:\n";
	for_each(vec.begin(), vec.end(), [](int i) {cout << i << '\t'; });
}