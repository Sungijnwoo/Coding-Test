#include <iostream>
#include <vector>
using namespace std;

// ģ������� �������ְ�
// �Ѹ��� ���� ģ���鵵 �������� �������� ������ ���� �������ִ�.
// dfs? visited?
// ĵ�� ���� ���� �湮�� ������ �����ֱ�
// ĵ��, ģ���� �� �̿��� ���� ������ �ذ��ϱ�

int dfs(vector<vector<int>>& graph, vector<int>& candies, int idx,int& count)
{
	// �̹� �湮������ ����
	if (candies[idx] == 0)
		return 0;
	++count;
	// �湮 ó��
	int value = candies[idx];
	candies[idx] = 0;


	// ģ���� ã�Ƽ� ĵ�� ���ƹޱ�
	for (int i = 0; i < graph[idx].size(); ++i)
	{
		value += dfs(graph, candies, graph[idx][i], count);
	}

	return value;
}

void getAns(vector<pair<int, int>>& groups, int idx, int k, int candies,int friends, int& ans)
{
	int currentFriends = friends + groups[idx].second;
	int currentCandy = candies + groups[idx].first;

	if (idx >= groups.size() || currentFriends >= k)
		return;



	if (currentCandy > ans)
		ans = currentCandy;
	getAns(groups, idx + 1, k, currentCandy, currentFriends, ans);
	getAns(groups, idx + 1, k, candies, friends, ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> candies(n + 1);
	vector<vector<int>> graph(n + 1);

	// candy, friend
	vector<pair<int,int>> candyGroups;

	vector<int> dp(k,0);

	for (int i = 1; i <= n; ++i)
	{
		cin >> candies[i];
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
	{
		int count = 0;
		int candySum = dfs(graph,candies,i,count);

		if (candySum)
			candyGroups.push_back({ candySum,count });
	}

	for (int i = 0; i < candyGroups.size(); ++i)
	{
		int currentCandy = candyGroups[i].first;
		int currentFriend = candyGroups[i].second;
		for (int j = k - 1; j >= currentFriend ; --j) 
		{
			dp[j] = max(dp[j], dp[j - currentFriend] + currentCandy);
		}
	}

	cout << dp[k - 1];

	/*int ans = 0;
	getAns(candyGroups, 1, k, 0, 0, ans);

	cout << ans; */
}