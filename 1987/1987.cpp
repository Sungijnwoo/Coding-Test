#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, maxCount = 0;

struct elem
{
	int count;
	int mask;
	int x;
	int y;
};

void dfs(vector<string>& board, int count, int mask, int x, int y)
{
	if ((mask & (1 << (board[x][y] - 'A'))))
	{
		return ;
	}

	mask = mask | (1 << (board[x][y] - 'A'));
	maxCount = max(maxCount, count + 1);
	if (x - 1 >= 0 && (mask & (1 << (board[x - 1][y] - 'A'))) == 0)
		dfs(board, count + 1, mask, x - 1, y);
	if (x + 1 < R && (mask & (1 << (board[x + 1][y] - 'A'))) == 0)
		dfs(board, count + 1, mask, x + 1, y);
	if (y - 1 >= 0 && (mask & (1 << (board[x][y - 1] - 'A'))) == 0)
		dfs(board, count + 1, mask, x, y - 1);
	if (y + 1 < C && (mask & (1 << (board[x][y + 1] - 'A'))) == 0)
		dfs(board, count + 1, mask, x, y + 1);
}

int main()
{
	cin >> R >> C;

	vector<string> board;

	for (int i = 0; i < R; ++i)
	{
		string input;
		cin >> input;
		board.push_back(input);
	}

	dfs(board, 0, 0, 0, 0);

	//// cout, mask
	//queue<elem> q;

	//q.push({ 0,0,0,0 });

	//while (!q.empty())
	//{
	//	elem front = q.front();
	//	q.pop();

	//	// 아직 방문안했으면
	//	if (((1 << (board[front.x][front.y] - 'A')) & front.mask)==0)
	//	{
	//		front.mask = front.mask | (1 << (board[front.x][front.y] - 'A'));

	//		++front.count;
	//		if (front.x - 1 >= 0 && (front.mask &(1<< (board[front.x-1][front.y] - 'A')))==0)
	//		{
	//			q.push({ front.count,front.mask,front.x - 1,front.y });
	//		}
	//		if (front.x + 1 < R && (front.mask & (1<<(board[front.x + 1][front.y] - 'A'))) == 0)
	//		{
	//			q.push({ front.count,front.mask,front.x + 1,front.y });
	//		}
	//		if (front.y - 1 >= 0 && (front.mask & (1<<(board[front.x][front.y - 1] - 'A'))) == 0)
	//		{
	//			q.push({ front.count,front.mask,front.x,front.y - 1 });
	//		}
	//		if (front.y + 1 < C && (front.mask & (1<<(board[front.x][front.y + 1] - 'A'))) == 0)
	//		{
	//			q.push({ front.count,front.mask,front.x,front.y + 1 });
	//		}
	//	}
	//	
	//	maxCount = max(maxCount, front.count);
	//}

	cout << maxCount << endl;
}