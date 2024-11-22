#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin.tie(0)->sync_with_stdio(0);
		cout.tie(0);

		int N, ans=0;
		cin >> N;

		vector<vector<int>> st(N + 1); 
		vector<int> inDegree(N + 1);
		queue<int> q; 
		for (int i = 1; i <= N; ++i)
		{
			int choose;
			cin >> choose;

			st[i].push_back(choose);

			++inDegree[choose];
		}

		for (int i = 1; i <= N; ++i)
		{
			if (!inDegree[i])
				q.push(i);
		}

		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			++ans;
			for (int i = 0; i < st[current].size(); ++i)
			{
				if (--inDegree[st[current][i]] == 0)
				{
					q.push(st[current][i]);
				}
			}
		}

		cout << ans<<" ";
		
		// 루프찾기
	}
}