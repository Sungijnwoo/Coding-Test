#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	// �Ѱ谡 100�� ����
	// ���� �ִ�� �ޱ�
	// �׷��� ����ä��� �ȵȴ�.
	vector<int> hp(N+1);
	vector<int> happy(N+1);
	// vector<vector<int>> dp(N+1,vector<int>(100));
	vector<int> dp(101);
	for (int i = 1; i <= N; ++i)
	{
		cin >> hp[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		cin >> happy[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 99; j >= hp[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - hp[i]] + happy[i]);
		}
	}

	cout << dp[99];
}