#include <iostream>
using namespace std;

int dp[21][21][21];



void w(int a, int b, int c)
{
	cout << "w(" << a << ", " << b << ", " << c << ") = ";
	if (a <= 0 || b <= 0 || c <= 0)
	{
		cout<< 1 << " ";
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		cout << dp[20][20][20] << " ";
	}
	else
	{
		cout << dp[a][b][c] << " ";
	}


}

int main()
{

	for (int i = 0; i <= 20; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			for (int k = 0; k <= 20; ++k)
			{
				if (i <= 0 || j <= 0 || k <= 0)
				{
					dp[i][j][k] = 1;
				}
				else if (i < j && j < k)
				{
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				}
				else
				{
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}


	int input[3];



	while (true)
	{
		for (int i = 0; i < 3; ++i)
		{
			cin >> input[i];
		}
		if (input[0] == -1 && input[1] == -1 && input[2] == -1)
		{
			break;
		}

		w(input[0], input[1], input[2]);

	}


}