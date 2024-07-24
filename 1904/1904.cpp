#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;

	if (N == 1)
		cout << 1 << endl;
	else if (N == 2)
		cout << 2 << endl;

	for (int i = 3; i <= 1000000; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
		if (i == N)
		{
			cout << dp[i] << endl;
			break;
		}
	}

}