#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<pair<int, int>>>& tree, vector<bool>& visited, int idx, int length, int& maxLength, int& maxIdx)
{
	int size = tree[idx].size();


	// 방문한 idx에 routeStart 값이 있고 first값과 현재 idx값이 일치하지 않으면 해당값으로 maxLen에 더해주고 끝내기.

	if (maxLength < length)
	{
		maxLength = length;
		maxIdx = idx;
	}

	for (int i = 0; i < size; ++i)
	{
		if (!visited[tree[idx][i].first])
		{
			visited[tree[idx][i].first] = true;

			dfs(tree, visited, tree[idx][i].first, length+tree[idx][i].second, maxLength,maxIdx);
		}
	}
	
}

int main()
{	
	int n;
	cin >> n;

	vector<vector<pair<int, int>>> tree(n+1);
	for (int i = 0; i < n-1; ++i)
	{
		int parent, child, value;
		cin >> parent >> child >> value;

		tree[parent].push_back({ child,value });
		tree[child].push_back({ parent,value });
	}

	
	
	vector<bool> visited(n);


		visited[1] = true;

		int maxlen = 0;
		int maxIdx = 0;

		dfs(tree, visited, 1, 0, maxlen, maxIdx);
		int maxlen2 = 0;
		int tmp = 0;
		visited = vector<bool>(n);
		visited[maxIdx] = true;
		dfs(tree, visited, maxIdx, 0, maxlen2,tmp);

		cout << max(maxlen, maxlen2) << endl;

	

}