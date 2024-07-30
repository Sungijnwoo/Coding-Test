#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> num(N+1,vector<int>(11,0));

	for (int i = 1; i < 10; ++i)
	{
		num[1][i] = 1;
	}

	for (int size = 2; size <= N; ++size)
	{
		num[size][0] = num[size - 1][1];
		for (int i = 1; i < 10; ++i)
		{
			num[size][i] = (num[size - 1][i - 1] + num[size - 1][i + 1]) % 1000000000;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 10;++i)
	{
		ans = (ans + num[N][i]) % 1000000000;
	}
	cout << ans;
}