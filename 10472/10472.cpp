#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;


struct clickBoard
{
	int clickPos;
	int board;
	int count;
};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int Click(int board, int clickPos)
{
	int row = clickPos / 3;
	int col = clickPos % 3;

	board ^= (1 << clickPos);
	for (int i = 0; i < 4; ++i)
	{
		if (row + dx[i] < 0 || row + dx[i] >= 3 || col + dy[i] < 0 || col + dy[i] >= 3)
		{
			continue;
		}
		board ^= (1 << (3 * (row + dx[i]) + col + dy[i]));
	}
	return board;
}

int main()
{
	int P;
	cin >> P;

	

	while (P--)
	{
		int inputBoard = 0;
		bitset<(1<<9)> check;
		for (int i = 0; i < 3; ++i)
		{
			string input;
			cin >> input;
			for (int j=0;j<3;++j)
			{
				if (input[j] == '*')
					inputBoard |= (1 << (3*i + j));
			}
		}

		queue<int> Q;
		Q.push(0);
		int level = 0;
		while (!Q.empty())
		{
			
			int qsize = Q.size();
			while (qsize--)
			{
				int current = Q.front();
				Q.pop();

				if (current == inputBoard)
				{
					cout << level << "\n";
					break;
				}
				for (int i = 0; i < 9; ++i)
				{
					int val = current;

					val = Click(val, i);

					if (!check[val])
					{
						check[val] = 1;
						Q.push(val);
					}
				}
			}
			++level;
		}

		//queue<clickBoard> q;
		//
		//for (int i = 0; i < 9; ++i)
		//{
		//	q.push({ i, 0,0 });
		//}

		//while (!q.empty())
		//{
		//	clickBoard current = q.front();
		//	q.pop();

		//	if (current.board == inputBoard)
		//	{
		//		cout << current.count << "\n";
		//		break;
		//	}
		//	
		//	int result = Click(current.board, current.clickPos);
		//	if (check[result])
		//	{
		//		continue;
		//	}
		//	else
		//	{
		//		check[result] = 1;
		//	}
		//		

		//	// 클릭 처리한 board를 q에 넣어준다.
		//	// q.push(i(0~8),board,count+1);
		//	for (int i = 0; i < 9; ++i)
		//	{
		//		q.push({ i, result, current.count + 1 });
		//	}
		//}
	
	}
}