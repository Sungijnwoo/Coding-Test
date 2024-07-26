#include <iostream>
using namespace std;

int main()
{
	int n,ans=0;
	cin >> n;

	int tri[500][500];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> tri[i][j];
			if (j == 0)
			{
				tri[i][j] += tri[i - 1][j];
			}
			else if (j == i)
			{
				tri[i][j] += tri[i - 1][j - 1];
			}
			else
			{
				tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, tri[n-1][i]);
	}
	cout << ans;
}