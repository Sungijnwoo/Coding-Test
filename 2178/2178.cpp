#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct dat
{
	int x;
	int y;
	int count;
};

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<string> maze;
	// 입력이 빈칸없이 주어지기 때문에 string으로 받는다.
	for (int i = 0; i < N; ++i)
	{
		string temp;
		cin >> temp;
		maze.push_back(temp);
	}

	queue<dat> q;

	q.push({ 0,0,1 });
	while (!q.empty())
	{
		dat top = q.front();
		q.pop();
		if (top.x == N - 1 && top.y == M - 1)
		{
			cout << top.count << endl;
			break;
		}
		if (top.x>=0&&top.y>=0&&top.x<N&&top.y<M&&maze[top.x][top.y]=='1')
		{
			q.push({ top.x,top.y + 1,top.count + 1 });
			q.push({ top.x,top.y - 1,top.count + 1 });
			q.push({ top.x + 1,top.y,top.count + 1 });
			q.push({ top.x - 1,top.y,top.count + 1 });
			maze[top.x][top.y] = '0';
		}
	}

	
}