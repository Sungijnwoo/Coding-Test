#include <iostream>
#include <vector>
#include <queue>	
#include <algorithm>
using namespace std;


// �������� ũ�� - ���� ���� + ���̷����� ���� = ���� ������ �̿��Ѵ�.
int virusCountBFS(vector<vector<int>> lab, vector<pair<int, int>> wallPos, vector<pair<int,int>>& virusPos)
{
	int count = 0;
	int N = lab.size();
	int M = lab[0].size();
	// �� �����
	for (int i = 0; i < wallPos.size(); ++i)
	{
		int x = wallPos[i].first;
		int y = wallPos[i].second;

		lab[x][y] = 1;
	}
	
	queue<pair<int, int>> q;
	for (int i = 0; i < virusPos.size(); ++i)
	{
		q.push(virusPos[i]);
	}
	
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	while (!q.empty())
	{
		// ���̷����� ����
		pair<int, int> top = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = top.first + dx[i];
			int y = top.second + dy[i];

			if (x >= 0 && y >= 0 && x < N && y < M && lab[x][y] == 0)
			{
				q.push({ x,y });
				lab[x][y] = 2;
				++count;
			}
		}
	}

	// �� ������ ���� ������ ����
	return count + virusPos.size();

}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, virusQty,ans=0,wallQty=0;
	cin >> N >> M;

	vector<vector<int>> lab(N, vector<int>(M));
	vector<pair<int, int>> virusPos;
	vector<pair<int, int>> wallPos;
	vector<int> perm(N*M-3,0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 2)
				virusPos.push_back({ i,j });
			else if (lab[i][j] == 1)
				++wallQty;
		}
	}

	// 0~7 �� ������ ������ ������ ũ�� 2�� ���� 3���� �ߺ����� �ʰ� �̱�. -> N*M ���� ĭ���� 3�� �̱� row = i/M, col = i%M
	for (int i = 0; i < 3; ++i)
	{
		perm.push_back(1);
	}
	do
	{
		for (int i = 0; i < perm.size(); ++i)
		{
			if (perm[i])
			{
				//cout << i << endl;
				int x = i / M;
				int y = i % M;
				if (lab[x][y])
					break;
				wallPos.push_back({ x,y });
			}
		}
		if (wallPos.size() == 3)
		{
			//cout << "@@" << endl;
			virusQty = virusCountBFS(lab, wallPos, virusPos);
			ans = max(ans, N * M - 3 - wallQty - virusQty);
		}
		wallPos.clear();
	} while (next_permutation(perm.begin(),perm.end()));

	cout << ans;
	

}