#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> questions(N+1);
	vector<int> inDegree(N+1);
	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		questions[a].push_back(b);
		++inDegree[b];
	}
	for (int i = 1; i <= N; ++i)
	{
		if (inDegree[i] == 0)
			pq.push(i);
	}

	for (int i = 0; i < N; ++i)
	{
		int current = pq.top();
		pq.pop();

		cout << current << " ";

		for (int j = 0; j < questions[current].size(); ++j)
		{
			if (--inDegree[questions[current][j]] == 0)
			{
				pq.push(questions[current][j]);
			}
		}
	}

}