#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DesVal
{
	int des;
	int val;

	bool operator<(const DesVal dv) const
	{
		return this->val > dv.val;
	}
};

int main()
{
	int N, M, start, end, ans = -1;
	cin >> N >> M;

	vector<vector<int>> cities(N + 1, vector<int>(N + 1, -1));
	vector<bool> visited(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int src, des, val;
		cin >> src >> des >> val;

		if (cities[src][des] == -1)
			cities[src][des] = val;
		else
			cities[src][des] = min(cities[src][des], val);
	}

	cin >> start >> end;

	if (start == end)
	{
		cout << 0 << endl;
		return 0;
	}
	visited[start] = true;

	priority_queue<DesVal> q;
	for (int i = 0; i < cities[start].size(); ++i)
	{
		if (cities[start][i] != -1)
			q.push({ i,cities[start][i] });
	}

	while (!q.empty())
	{
		DesVal current = q.top();


		q.pop();

		if (visited[current.des])
			continue;
		else
		{
			visited[current.des] = true;
		}

		if (current.des == end)
		{
			cout << current.val << endl;
			return 0;
		}

		for (int i = 0; i < cities[current.des].size(); ++i)
		{
			if (cities[current.des][i] != -1)
			{
				cities[current.des][i] += current.val;
				q.push({ i,cities[current.des][i] });
			}
		}
	}
}