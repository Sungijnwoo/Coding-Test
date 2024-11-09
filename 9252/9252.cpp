#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	// 가장 긴 LCS 길이 찾기
	vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1));

	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	if (dp.back().back() == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << dp.back().back() << endl;

	// LCS 길이를 찾으며 만들어둔 dp를 통해 뒤에서부터 문자열 조립하기
	int i = a.size();
	int j = b.size();
	string answer = "";
	while (answer.size()<dp.back().back())
	{
		if (a[i-1] == b[j-1])
		{
			answer = a[i-1] + answer;
			--i;
			--j;
		}
		else
		{
			if (dp[i - 1][j] > dp[i][j - 1])
				--i;
			else
				--j;
		}
	}
	cout << answer; 
}