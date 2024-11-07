#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int leftAns = 0;
	int rightAns = 0;
	int mix = INT32_MAX;
	vector<int> solutions(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> solutions[i];
	}

	sort(solutions.begin(), solutions.end());

	int leftIdx = 0;
	int rightIdx = N - 1;

	while (leftIdx < rightIdx)
	{
		int left = solutions[leftIdx];
		int right = solutions[rightIdx];

		int result = abs(left + right);
		if (result < mix)
		{
			mix = result;
			leftAns = left;
			rightAns = right;
		}

		if (left + right > 0)
		{
			--rightIdx;
		}
		else
		{
			++leftIdx;
		}
	}

	cout << leftAns << " " << rightAns << endl;
}