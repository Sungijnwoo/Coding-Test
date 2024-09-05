#include <iostream>
#include <vector>
using namespace std;

int n;



void dfs(vector<vector<int>>& tree, vector<int>& parents, vector<bool>& visited, int currentIdx)
{
	int size = tree[currentIdx].size();

	for (int i = 0; i < size; ++i)
	{
		if (visited[tree[currentIdx][i]])
			continue;
		visited[tree[currentIdx][i]] = true;
		parents[tree[currentIdx][i]] = currentIdx;
		dfs(tree, parents, visited, tree[currentIdx][i]);
	}
}

int main()
{
	cin >> n;

	vector<vector<int>> tree(n+1);
	vector<int> parents(n + 1);
	vector<bool> visited(n + 1);
	for (int i = 0; i < n-1; ++i)
	{
		int node1,node2;
		cin >> node1>>node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	visited[1] = true;
	dfs(tree, parents,visited, 1);

	for (int i = 2; i < n + 1; ++i)
	{
		cout << parents[i] << "\n";
	}
}