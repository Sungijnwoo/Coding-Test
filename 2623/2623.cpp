#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> ord(N+1);
	vector<int> inDegree(N+1);
	queue<int> q;
	vector<int> answer;
	
	for (int i = 0; i < M; ++i)
	{
		int p;
		cin >> p;

		int prev;
		cin >> prev;
		for (int j = 0; j < p-1; ++j)
		{
			int current;
			cin >> current;

			ord[prev].push_back(current);
			++inDegree[current];
			prev = current;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!inDegree[i])
			q.push(i);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (q.empty())
		{
			cout << 0;
			return 0;
		}

		int current = q.front();
		q.pop();

		answer.push_back(current);


		for (int singer : ord[current])
		{
			if (--inDegree[singer] == 0)
				q.push(singer);
		}
	}

	for (int num : answer)
		cout << num << "\n";
}