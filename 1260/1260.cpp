#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(vector<vector<bool>>& gr, vector<bool>& visited, int idx)
{
	printf("%d ", idx);
	visited[idx] = 1;
	int size = gr[idx].size();
	for (int i = 0; i < size; ++i)
	{
		if (gr[idx][i] && !visited[i])
		{
			DFS(gr, visited, i);
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<bool>> graph(N + 1, vector<bool>(N + 1));
	vector<bool> visited(N, 0);
	while (M--)
	{
		int src, dst;
		cin >> src >> dst;
		graph[src][dst] = 1;
		graph[dst][src] = 1;
	}

	// DFS
	DFS(graph, visited, V);
	printf("\n");

	// BFS
	queue<int> q;
	q.push(V);

	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (visited[top])
		{
			printf("%d ", top);
			visited[top] = 0;
			for (int i = 0; i <= N; ++i)
			{
				if (graph[top][i])
				{
					q.push(i);
				}
			}
		}
		
	}
}