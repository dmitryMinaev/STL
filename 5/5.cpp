#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	vector<string> vec
	{
		"Wfdsf",
		"wFdsf",
		"aWas",
		"ABas",
		"odfdas"
	};

	cout << "Before:\n";
	for_each(vec.begin(), vec.end(), [](string i) {cout << i << '\t'; });

	auto ToLower = [](string s) -> string
	{
		int i = 0;
		while (i < s.length())
		{
			s[i] = tolower(s[i]);
			i++;
		}

		return s;
	};

	auto funcSort = [ToLower](string i, string j)
	{
		return ToLower(i) < ToLower(j);
	};

	sort(vec.begin(), vec.end(), funcSort);

	cout << "\nAfter:\n";
	for_each(vec.begin(), vec.end(), [](string i) {cout << i << '\t'; });
}