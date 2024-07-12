#include <iostream>
#include <vector>
using namespace std;


int Cal(vector<vector<int>>& statTable, int maxBit, int teamA)
{
	int teamB = ~teamA;
	int StatSub = 0;
	for (int i = 0; i < maxBit; ++i)
	{
		if (teamA & (1 << i))
		{
			for (int j = 0; j < maxBit; ++j)
			{
				if (teamA & (1 << j))
				{
					StatSub += statTable[i][j];
				}
			}
		}
	}

	for (int i = 0; i < maxBit; ++i)
	{
		if (teamB & (1 << i))
		{
			for (int j = 0; j < maxBit; ++j)
			{
				if (teamB & (1 << j))
				{
					StatSub -= statTable[i][j];
				}
			}
		}
	}
	return abs(StatSub);
}

int main()
{
	int N;
	cin >> N;

	int TeamA = 1;

	vector<vector<int>> arr(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int MAX = (1 << N) -1;
	int ans = Cal(arr, N, TeamA);
	++TeamA;
	while (TeamA < MAX)
	{
		ans = min(ans, Cal(arr, N, TeamA));
		++TeamA;
	}

	cout << ans << endl;

	return 0;
}