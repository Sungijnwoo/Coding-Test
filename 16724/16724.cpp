#include <iostream>
#include <vector>
using namespace std;

// 루프 갯수 찾기

// d, u , l, r
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int ans = 0;

void dfs(vector<vector<short>>& graph, vector<vector<int>>& visited, int x, int y, int mark)
{
	if (visited[x][y] == mark)
	{
		++ans;
		return;
	}
	
	if (visited[x][y] != 0)
	{
		// 이미 루프 확인한 구역
		return;
	}
	
	visited[x][y] = mark;
	short tmp = graph[x][y];
	dfs(graph, visited, st, x + dx[tmp], y + dy[tmp], mark);
}


int main()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0);

	int n, m;
	cin >> n>> m;

	vector<vector<short>> map(n, vector<short>(m));
	vector<vector<int>> visited(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;

			int input;
			switch (c)
			{
			case('D'):
				input = 0;
				break;
			case('U'):
				input = 1;
				break;
			case('L'):
				input = 2;
				break;
			case('R'):
				input = 3;
			default:
				break;
			}

			map[i][j] = input;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			dfs(map, visited, i, j, i * m + j + 1);
		}
	}

	cout << ans;
}