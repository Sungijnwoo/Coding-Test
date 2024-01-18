#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Dat
{
	int x, y, day;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, ans=0;
	cin >> M >> N;

	vector<vector<int>> box(N,vector<int>(M));
	queue<Dat> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int val;
			cin >> val;
			box[i][j] = val;
			if(val==1)
			{ 
				q.push({ i, j, 1 });
			}
		}
	}

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	while (!q.empty())
	{
		Dat top = q.front();
		int x = top.x;
		int y = top.y;
		int day = top.day;
		q.pop();
		ans = max(ans, day);
		for (int i = 0; i < 4; ++i)
		{
			int _x = x + dx[i];
			int _y = y + dy[i];

			// q에 푸쉬해주면서 현재 위치 체크해서 중복 방지, 큐에 조건 확인하고 넣기 때문에 메모리 줄임
			if (_x >= 0 && _y >= 0 && _x < N && _y < M && box[_x][_y] == 0)
			{
				q.push({ _x,_y,day + 1 });
				box[_x][_y] = day;
			}
		}
	}
	
	bool hasZero = false;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (box[i][j] == 0)
			{
				hasZero = true;
			}
		}
	}

	if(hasZero) 
		cout << -1;
	else 
		cout << ans-1;
}