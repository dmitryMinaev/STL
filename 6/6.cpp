#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(map<int, string> t)
{
	set<string> res;
	for (auto item : t)
		res.insert(item.second);

	return res;
}

int main()
{
	map<int, string> m
	{
		{1, "even" },
		{2, "even" },
		{3, "story" },
		{4, "even" },
		{5, "odd" },
		{6, "even" },
		{7, "odd" },
		{8, "story" },
	    {9, "qwerty"}
	};

	set<string> s = BuildMapValuesSet(m);

	for (auto item : s)
		cout << item << '\t';
}