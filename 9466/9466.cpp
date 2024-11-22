#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& st, int idx, int mark)
{
	
	if (visited[idx] == mark)
	{
		int current = 0;
		while (!st.empty()&&current != idx)
		{
			current = st.back();
			visited[current] = -1;
			st.pop_back(); 
		}
		return;
	}

	if (visited[idx])
		return;

	visited[idx] = mark;

	st.push_back(idx);

	dfs(graph, visited, st, graph[idx].back(), mark);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int N, ans=0;
		cin >> N;

		vector<vector<int>> graph(N + 1);

		vector<int> visited(N + 1,0);

		vector<int> st;

		for (int i = 1; i <= N; ++i)
		{
			int des;
			cin >> des;

			graph[i].push_back(des);
		}

		for (int i = 1; i <= N; ++i)
		{
			dfs(graph, visited, st, i, i);
		}

		cout << st.size() << " ";

		/*vector<vector<int>> st(N + 1); 
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

		cout << ans<<" ";*/
		
		// 루프찾기
	}
}