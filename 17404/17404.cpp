#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> homes(N, vector<int>(3));
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(3,1000001)));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> homes[i][j];
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		dp[0][i][i] = homes[0][i];
	}

	for (int i = 1; i < N; ++i)
	{
		// ÇöÀç »ö±ò
		for (int j = 0; j < 3; ++j)
		{
			// ÀÌÀü »ö±ò
			for (int p = 0; p < 3; ++p)
			{
				if (p == j)
					continue;
				// ½ÃÀÛÁ¡ »ö±ò
				for (int k = 0; k < 3; ++k)
				{
					if (dp[i][j][k] == 1000001)
						dp[i][j][k] = dp[i - 1][p][k] + homes[i][j];
					else
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][p][k] + homes[i][j]);
				}
			}
		}
	}
	int minValue = 10000000;
	for (int j = 0; j < 3; ++j)
	{
		for (int k = 0; k < 3; ++k)
		{
			if (j == k)
				continue;
			minValue = min(minValue, dp.back()[j][k]);
		}
	}
	cout << minValue;
}