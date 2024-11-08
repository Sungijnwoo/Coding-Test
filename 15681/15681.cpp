#include <iostream>
#include <vector>
using namespace std;



int getNodes(vector<vector< int>>& graph, vector<int>& visited, int node)
{
	// 상위 노드 
	if (visited[node] != 0)
		return 0;

	if (visited[node] > 0)
	{
		return visited[node];
	}

	visited[node] = 1;

	int result = 0;
	for (int i = 0; i < graph[node].size(); ++i)
	{
		result += getNodes(graph, visited, graph[node][i]);
	}

	visited[node] += result;

	return visited[node];
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::cin.tie(NULL);

	std::cout.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;
	

	vector<vector<int>> graph(N+1);
	vector<int> nodeValues(N + 1,0);

	for (int i = 0; i < N-1; ++i)
	{
		int U, V;
		cin >> U >> V;

		graph[U].push_back({ V });
		graph[V].push_back({ U });
	}

	getNodes(graph, nodeValues, R);

	for (int i = 0; i < Q; ++i)
	{
		int U;
		cin >> U;

		cout << nodeValues[U] << "\n";
	}
}