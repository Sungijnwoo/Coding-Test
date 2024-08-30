#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<pair<int, int>>>& tree, vector<bool>& visited, int idx, long long length, int& maxIdx, long long& maxLength)
{
	int size = tree[idx].size();

	if (maxLength < length)
	{
		maxLength = length;
		maxIdx = idx;
	}

	for (int i = 0; i < size; ++i)
	{
		if (visited[tree[idx][i].first])
			continue;
		visited[tree[idx][i].first] = true;
		dfs(tree, visited, tree[idx][i].first, length + tree[idx][i].second, maxIdx, maxLength);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int v;
	cin >> v;

	vector<vector<pair<int, int>>> tree(v + 1);

	for (int i = 1; i <= v; ++i)
	{
		int parent;
		cin >> parent;

		while (true)
		{
			int child, value;
			cin >> child;
			if (child == -1)
				break;
			cin >> value;
			tree[parent].push_back({ child,value });
		}
	}

	int firstDes = 0, temp = 0;
	long long maxLength = 0;
	vector<bool> visited(v + 1);

	visited[1] = true;

	dfs(tree, visited, 1, 0, firstDes, maxLength);

	maxLength = 0;

	visited = vector<bool>(v + 1);
	visited[firstDes] = true;
	dfs(tree, visited, firstDes, 0, temp, maxLength);


	cout << maxLength << endl;
}