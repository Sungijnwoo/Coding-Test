#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<long long> solutions(N);
	vector<long long> answer(3);
	long long res = (long long)1 << 32;
	for (int i = 0; i < N; ++i)
	{
		cin >> solutions[i];
	}

	sort(solutions.begin(), solutions.end());

	
	for (int i = 0; i < N - 1; ++i)
	{
		int j = i + 1;
		int k = N - 1;

		while (j < k)
		{
			long long sum = solutions[i] + solutions[j] + solutions[k];
			if (abs(sum) < res)
			{
				res = abs(sum); 
				answer = { solutions[i],solutions[j],solutions[k] };
			}

			if (sum < 0)
				++j;
			else
				--k; 
		}
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < 3; ++i)
	{
		cout << answer[i] << " ";
	}
}

// -97 -6 -2 6 98
// -24 -6 -3 -2 61 98 100