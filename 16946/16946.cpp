#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void dfs(vector<vector<int>>& map, int x, int y, int checker, int& result)
{
	if (map[x][y])
	{
		return;
	}
	++result;
	map[x][y] = checker; 
	for (int i = 0; i < 4; ++i)
	{
		int mvX = x + dx[i];
		int mvY = y + dy[i];

		if (mvX < 0 || mvY < 0 || mvX >= map.size() || mvY >= map.back().size() || map[mvX][mvY])
		{
			continue;
		}
		dfs(map, mvX, mvY, checker, result);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n,vector<int>(m));
	vector<int> checkValue = { 0 };
	for (int i = 0; i < n; ++i)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; ++j)
		{
			map[i][j] = input[j] - '0';
		}
	}

	// 체커로 공백 그룹화
	int checker = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 0)
			{
				int result = 0;
				dfs(map, i, j, checker,result);
				--checker;
				checkValue.push_back(result);
			}
		}
	}

	// 순회하면서 벽이 있는 곳 기점 4방향만 확인해서
	// 그룹화 해둔 공백의 넓이값만 더해주기
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] != 1)
			{
				cout << 0;
				continue;
			}
			int result = 1;
			vector<bool> visited(checkValue.size());
			for (int k = 0; k < 4; ++k)
			{
				int mvX = i + dx[k];
				int mvY = j + dy[k];

				if (mvX < 0 || mvY < 0 || mvX >= map.size() || mvY >= map.back().size())
				{
					continue;
				}
				// 중복된 그룹 더하기 방지용
				if (map[mvX][mvY] < 0 && !visited[-map[mvX][mvY]])
				{
					result += checkValue[-map[mvX][mvY]];
					visited[-map[mvX][mvY]] = true;
				}
			}
			cout << result % 10;
		}
		cout << "\n";
	}

	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}*/
}