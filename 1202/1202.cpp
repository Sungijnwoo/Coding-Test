#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	// weights , prices
	vector<pair<int, int>> jews(n);
	vector<int> bags(k);

	priority_queue<int> pq;

	for (int i = 0; i < n; ++i)
	{
		int m, v;
		cin >> m >> v;
		jews[i] = { m,v };
	}

	for (int i = 0; i < k; ++i)
	{
		int bag;
		cin >> bag;
		bags[i] = bag;
	}

	sort(bags.begin(), bags.end());  
	sort(jews.begin(), jews.end());
	long long ans = 0;
	
	int idx = 0;
	for (int bag : bags)
	{
		while (idx < n && jews[idx].first <= bag)
		{
			pq.push(jews[idx].second);
			++idx;
		}

		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}