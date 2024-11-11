#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool rows[10][10];
bool cols[10][10];
bool sqrs[10][10];

struct candi
{
	int x;
	int y;
	
	candi(int a, int b)
	{
		x = a;
		y = b;
	}
};


bool checkSdoku(vector<vector<int>>& sdoku, vector<candi>& candidates, int idx)
{
	if (idx >= candidates.size())
	{
		for (int i = 1; i <= 9; ++i)
		{
			for (int j = 1; j <= 9; ++j)
			{
				cout << sdoku[i][j];
			}
			cout << "\n";
		}
		return true;
	}

	candi& current = candidates[idx];

	for (int i = 1; i <= 9; ++i)
	{
		if (rows[current.x][i] == 0 && cols[current.y][i] == 0 && sqrs[(current.x - 1) / 3 * 3 + (current.y - 1) / 3 + 1][i] == 0)
		{
			sdoku[current.x][current.y] = i;

			rows[current.x][i] = true;
			cols[current.y][i] = true;
			sqrs[(current.x - 1) / 3 * 3 + (current.y - 1) / 3 + 1][i] = true;
			if (checkSdoku(sdoku, candidates, idx + 1))
				return true;
			rows[current.x][i] = false;
			cols[current.y][i] = false;
			sqrs[(current.x - 1) / 3 * 3 + (current.y - 1) / 3 + 1][i] = false;
			sdoku[current.x][current.y] = 0;
		}
	}

	return false;
}

int main()
{
	vector<vector<int>> sdoku(10, vector<int>(10));
	vector<candi> candidates;
	for (int i = 1; i <= 9; ++i)
	{
		string input; 
		cin >> input;

		for (int j = 1; j <= 9; ++j)
		{
			sdoku[i][j] = input[j-1] - '0';
			rows[i][sdoku[i][j]] = true;
			cols[j][sdoku[i][j]] = true;
			sqrs[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][sdoku[i][j]] = true;
			if (sdoku[i][j] == 0)
			{
				candidates.push_back(candi{ i,j });
			}
		}
	}

	
	 checkSdoku(sdoku, candidates,0);
	
}