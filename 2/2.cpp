#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> res;

	int resizeLength = words.size();

	auto funcPalindrom = [](string s) -> bool
	{
		int i = 0;
		while (i < s.length())
		{
			if (s[i] != s[s.length() - i - 1])
				return false;

			i++;
		}

		return true;
	};

	auto func = [funcPalindrom, minLength, &resizeLength](string i) -> bool
	{
		if (i.length() < minLength)
		{
			resizeLength--;
			return true;
		}
		else if (!funcPalindrom(i))
		{
			resizeLength--;
			return true;
		}

		return false;
	};

	auto iter = remove_if(words.begin(), words.end(), func);

	words.resize(resizeLength);

	return words;
}

int main()
{
	srand(time(0));
	vector<string> vec{ "absdsba", "asfsa", "qwerty", "qwfghgff", "s", "sd", "qwe", "qwjlty", "house", "pigip", "aba", "abababa"};

	int minLength = 4;
	auto res = PalindromFilter(vec, minLength);

	cout << "Min length:" << minLength << endl;

	for (auto item : res)
		cout << "Word:" << item << "\tLength:" << item.length() << '\n';

}