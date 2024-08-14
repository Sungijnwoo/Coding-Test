#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<long long> guitars(N);

	for (int i = 0; i < N; ++i)
	{
		string dummy,input;
		cin >> dummy >> input;

		for (int j = 0; j < input.size(); ++j)
		{
			if (input[j] == 'Y')
				guitars[i] |= ((long long)1 << j);
		}
	}
	int ans = -1;
	int songs = 0;
	for (int i = 1; i < (1 << N); ++i)
	{
		long long result = 0;
		int guitarCount = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i & (1 << j))
			{
				result |= guitars[j];
				++guitarCount;
			}
		}
		int songCount = 0;
		while (result > 0)
		{
			if (result & 1)
				++songCount;
			result = result >> 1;
		}

		if (songs < songCount)
		{
			songs = songCount;
			ans = guitarCount;
		}
		else if (songs == songCount)
		{
			ans = min(ans, guitarCount);
		}
	}

	cout << ans;
}