#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

void dfs(vector<vector<int>>& walls, vector<vector<int>>& visited,int row, int col,int& space,int visitedCheck)
{
	if (visited[row][col]>=0||row<0||row>=walls.size()||col<0||col>=walls.back().size())
		return;

	visited[row][col] = visitedCheck;

	++space;

	for (int i = 0; i < 4; ++i)
	{
		if (!(walls[row][col] & (1 << i)))
		{
			dfs(walls, visited, row + dx[i], col + dy[i], space, visitedCheck);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> walls(M, vector<int>(N));
	// visited로 방 구분할 수 있도록 함.
	vector<vector<int>> visited(M, vector<int>(N,-1));
	vector<int> roomSpace;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> walls[i][j];
		}
	}

	// 넓이 구하기
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int space = 0;
			dfs(walls, visited, i, j, space,roomSpace.size());

			if (space)
			{
				roomSpace.push_back(space);
			}
		}
	}
	int maxSpace = 0;
	for (int i = 0; i < roomSpace.size(); ++i)
	{
		maxSpace = max(maxSpace, roomSpace[i]);
	}

	int breakMaxSpace = 0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i - 1 >= 0)
			{
				if (visited[i][j] != visited[i - 1][j])
				{
					breakMaxSpace = max(breakMaxSpace, roomSpace[visited[i][j]] + roomSpace[visited[i - 1][j]]);
				}
			}
			if (j - 1 >= 0)
			{
				if (visited[i][j] != visited[i][j-1])
				{
					breakMaxSpace = max(breakMaxSpace, roomSpace[visited[i][j]] + roomSpace[visited[i][j-1]]);
				}
			}
		}

	}


	cout << roomSpace.size() << " " << maxSpace << " "<<breakMaxSpace;
}