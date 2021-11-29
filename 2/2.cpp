#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> res;

	int resizeLength = words.size();
	auto func = [minLength, &resizeLength](string i)
	{
		if (i.length() < minLength)
			resizeLength--;

		return i.length() < minLength;
	};

	auto iter = remove_if(words.begin(), words.end(), func);

	words.resize(resizeLength);

	return words;
}

int main()
{
	srand(time(0));
	vector<string> vec{ "absd", "asf", "qwerty", "qwfghgff", "s", "sd", "qwe", "qwjlty", "house", "pig" };

	int minLength = 8;
	auto res = PalindromFilter(vec, minLength);

	cout << "Min length:" << minLength << endl;

	for (auto item : res)
		cout << "Word:" << item << "\tLength:" << item.length() << '\n';

}