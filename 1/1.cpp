#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	vector<int> vec;

	for (int i = 0; i < 15; i++)
		vec.push_back(-50 + rand() % 85);

	for (auto item : vec)
		cout << item << '\t';

	cout << '\n' << *max_element(vec.begin(), remove_if(vec.begin(), vec.end(), [](int i) { return i >= 0 ? true : false; }), [](int x, int y) { return x < y;}) << '\n';
}