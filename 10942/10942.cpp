#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int nums[2000];
int dp[2000][2000];

bool getdp( int row, int col)
{
	if (row >= col)
		return dp[row][col] = 1;

	if (nums[row] != nums[col])
		return 0;

	if (dp[row][col] != -1)
		return dp[row][col]; 

	int ret = getdp(row + 1, col - 1);
	dp[row][col] = ret;
	return ret;


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	/*vector<vector<bool>> dp(N, vector<bool>(N,0));

	vector<int> nums(N);*/

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> nums[i];
		// nums.push_back(input);
	}

	

	/*for (int col = 0; col < N; ++col)
	{
		for (int row = 0; row <= col; ++row)
		{
			dp[row][col] = getdp(dp, nums, row, col);
		}
	}*/

	cin >> M;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		// cout << dp[s-1][e-1] << '\n';
		cout << getdp( s - 1, e - 1) << '\n';
	}


}