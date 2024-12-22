#include <iostream>
#include <vector>
using namespace std;

#define INF 10000



int main()
{
	int n, m, r, ans=0;
	cin >> n >> m >> r;

	vector<int> items(n + 1);
	vector<vector<int>> map(n+1,vector<int>(n+1,INF));

	for (int i = 1; i <= n; ++i)
	{
		cin>>items[i];
		map[i][i] = 0;
	}

	for (int i = 0; i < r; ++i)
	{
		int src, des, cost;
		cin >> src >> des >> cost;

		map[src][des] = cost;
		map[des][src] = cost;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];
			}
		}
	}


	
	for (int i = 1; i <= n; ++i)
	{
		int tmp = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (map[i][j] <= m)
				tmp += items[j];
		}
		ans = max(ans, tmp);
	}

	cout << ans;
}