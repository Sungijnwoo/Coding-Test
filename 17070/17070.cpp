#include <iostream>
#include <vector>
using namespace std;



int main()
{
	int n;
	cin >> n;

	vector<vector<bool>> graph(n+1, vector<bool>(n + 1));

	// 0 : 가로, 1 : 대각선, 2 : 세로
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1,vector<int>(3)));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int input;
			cin >> input;
			graph[i][j] = input;
		}
	}

	dp[1][2][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			
			if (!graph[i][j])
			{
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];
				dp[i][j][2] += dp[i - 1][j][1] + dp[i - 1][j][2];

				if(!graph[i-1][j]&&!graph[i][j-1])
					dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}

		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}