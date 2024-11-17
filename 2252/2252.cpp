#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> heights(N + 1);
	vector<int> inDegree(N + 1);
	queue<int> q;
	vector<int> answer;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		heights[a].push_back(b);
		++inDegree[b];
	}

	for (int i = 1; i <= N; ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= N; ++i)
	{
		int current = q.front();
		q.pop();
		answer.push_back(current);
		for (int j = 0; j < heights[current].size(); ++j)
		{
			if (--inDegree[heights[current][j]] == 0)
				q.push(heights[current][j]);
		}
	}

	for (int n : answer)
		cout << n << " ";
}