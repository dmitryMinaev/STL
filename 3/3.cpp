#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int k;
	cout << "N: ";
	cin >> k;

	vector<int> vec;

	int t;
	for (int i = 0; i < k; i++)
	{
		cout << "N + " << i << " >> ";
		cin >> t;
		vec.push_back(t);
	}

	double avg = accumulate(vec.begin(), vec.end(), 0);
	avg /= vec.size();

	cout << "\nInput: ";
	for_each(vec.begin(), vec.end(), [](int i) {cout << i << '\t'; });
	cout << '\n';

	cout << "K: " << count_if(vec.begin(), vec.end(), [avg](int x) {return x >= avg; }) << "\tAverage: " << avg << endl;

	cout << "Output: ";
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		if (*iter >= avg)
			cout << distance(vec.begin(), iter) << '\t';
	}
}