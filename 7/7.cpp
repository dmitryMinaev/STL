#include <iostream>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

vector<string> BuildCharCounters(map<string, string> m)
{
	vector<string> v(m.size());

	auto isRemove = [](string& s, char c) -> void
	{
		string str = "";
		int i = 0;
		while (i < s.length())
		{
			if (s[i] != c)
				str += s[i];
			i++;
		}

		s = str;
	};

	for (auto item : m)
	{
		int i = 0;
		string str = item.first;
		while (i < item.second.length())
		{
			isRemove(str, item.second[i]);
			i++;
		}

		v.push_back(str == "" ? "YES" : "NO");
	}

	return v;
}

int main()
{
	map<string, string> m
	{
		{"eat", "tea"},
		{"find", "search"},
		{"english", "shingle"},
		{"master", "stream"}
	};

	for (auto item : m)
		cout << item.first << '\t' << item.second << endl;

	auto v = BuildCharCounters(m);

	cout << '\n' << '\n';

	for (auto item : v)
		cout << item << endl;
}