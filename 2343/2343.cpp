#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N, M, mx = 0;
	cin >> N >> M;

	vector<int> lec(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> lec[i];
		mx = max(mx, lec[i]);
	}
	int ans = mx;

	long long lo = mx, ri = N * 10000;

	while (lo <= ri)
	{
		int length = (lo + ri) / 2, count = 1;
		long long blueray = 0;
		for (int i = 0; i < N; ++i)
		{
			if (blueray + lec[i] <= length)
			{
				blueray += lec[i];
			}
			else
			{
				blueray = lec[i];
				++count;
			}
		}

		if (count > M)
		{
			lo = length + 1;
		}
		else if (count <= M)
		{
			ri = length - 1;
			ans = length;
		}
		
	}
	cout << ans;
}