#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct app
{
	int mem;
	int cost;

	
};


int main()
{
	int N, M;
	cin >> N >> M;

	// 가방 : 비용
	vector<vector<int>> dp(N, vector<int>(10001));

	vector<app> apps(N);
	

	for (int i = 0; i < N; ++i)
	{
		int memIn;
		cin >> memIn;
		apps[i].mem = memIn;
	}

	int costSum = 0;
	for (int i = 0; i < N; ++i)
	{
		int costIn;
		cin >> costIn;
		apps[i].cost = costIn;
		costSum += costIn; 
	}




	 vector<int> dp(N * 100 + 1);
	for (int i = 0; i < N; ++i)
	{
		for (int j = costSum; j >= apps[i].cost; j--)
		{
			dp[j] = max(dp[j], dp[j - apps[i].cost] + apps[i].mem);
		}
	}

	for (int i = 0; i <= costSum; ++i)
	{
		if (dp[i] >= M)
		{
			cout << i;
			return 0;
		}
	}
}