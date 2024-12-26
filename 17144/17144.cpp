#include <iostream>
#include <vector>
using namespace std;

int dirx[4] = { 0,0,-1,1 };
int diry[4] = { 1,-1,0,0 };

int main()
{
	int r, c, t, ans = 0;
	cin >> r >> c >> t;

	vector<vector<int>> room(r, vector<int>(c));
	vector<vector<int>> add(r, vector<int>(c, 0));

	vector<int> puriPos;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> room[i][j];
			ans += room[i][j];
			if (room[i][j] == -1)
			{
				++ans;
				puriPos.push_back(i);
				puriPos.push_back(j);
			}
		}
	}

	while (t--)
	{
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				int dis = room[i][j] / 5;

				for (int k = 0; k < 4; ++k)
				{
					int posx = dirx[k] + i;
					int posy = diry[k] + j;

					if (posx >= 0 && posx < r && posy >= 0 && posy < c && room[posx][posy] != -1)
					{
						add[posx][posy] += dis;
						room[i][j] -= dis;
					}
				}
			}
		}

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				room[i][j] += add[i][j];
				add[i][j] = 0;
			}
		}


		// 공기 청정기에서 잘 안됨
		{
			int prev = 0;
			for (int i = 1; i < c; ++i)
			{
				int current = room[puriPos[0]][i];
				room[puriPos[0]][i] = prev;
				prev = current;
			}

			for (int i = puriPos[0] - 1; i >= 0; --i)
			{
				int current = room[i][c - 1];
				room[i][c - 1] = prev;
				prev = current;
			}

			for (int i = c - 2; i >= 0; --i)
			{
				int current = room[0][i];
				room[0][i] = prev;
				prev = current;
			}

			for (int i = 1; i < puriPos[0]; ++i)
			{
				int current = room[i][0];
				room[i][0] = prev;
				prev = current;
			}
			ans -= prev;
			prev = 0;

			for (int i = 1; i < c; ++i)
			{
				int current = room[puriPos[2]][i];
				room[puriPos[2]][i] = prev;
				prev = current;
			}

			for (int i = puriPos[2] + 1; i < r; ++i)
			{
				int current = room[i][c - 1];
				room[i][c - 1] = prev;
				prev = current;
			}

			for (int i = c - 2; i >= 0; --i)
			{
				int current = room[r - 1][i];
				room[r - 1][i] = prev;
				prev = current;
			}

			for (int i = r - 2; i > puriPos[2]; --i)
			{
				int current = room[i][0];
				room[i][0] = prev;
				prev = current;
			}
			ans -= prev;
		}


	}


	cout << ans;
}