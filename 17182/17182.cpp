#include <iostream>
#include <vector>
using namespace std;

int ans = (1 << 30);
void dfs(vector<vector<int>>& planets, int currentVisit,int src, int dest,int visitTime, int N)
{
	if (currentVisit == ((1 << N) - 1))
	{
		ans = min(ans, visitTime);
		return;
	}

	if (currentVisit & (1 << dest))
		return;

	currentVisit |= (1 << dest);

	visitTime += planets[src][dest];

	for (int i = 0; i < N; ++i)
	{
		dfs(planets, currentVisit, dest, i, visitTime, N);
	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	vector<vector<int>> planets(N,vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> planets[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				planets[i][j] = min(planets[i][j], planets[i][k] + planets[k][j]);
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		dfs(planets, 0, K, i, 0, N);
	}
	cout << ans;
}