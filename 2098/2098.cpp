#include <iostream>
#include <cstring>
using namespace std;

#define INF 987654321

int n, map[16][16];
int dp[16][1 << 16];

int dfs(int current, int visit)
{
	if (visit == ((1 << n) - 1))
	{
		if (map[current][0] == 0)
			return INF;
		return map[current][0];
	}

	if (dp[current][visit] != -1)
	{
		return dp[current][visit];
	}

	dp[current][visit] = INF;


	for (int i = 0; i < n; ++i)
	{
		if (map[current][i] == 0)
			continue;
		if ((visit & (1 << i)))
			continue;
		dp[current][visit] = min(dp[current][visit], map[current][i] + dfs(i, visit | (1 << i)));
	}

	return dp[current][visit];
}

int main()
{
	cin >> n;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1);
	
	return 0;
}