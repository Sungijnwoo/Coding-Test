#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;


	vector<int> onBits(20, 0);
	int input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		

		for (int j = 0; (1 << j) <= input; ++j)
		{
			if ((1 << j) & input)
				onBits[j]++;
		}

	}
	if (N == 1)
	{
		cout << input;
		return 0;
	}
	long long total = 0;
	for (int i = 0; i < 20; ++i)
	{
		long long OnBit = onBits[i];
		total += OnBit * (N - OnBit) * (1 << i);
	}

	cout << total;

}