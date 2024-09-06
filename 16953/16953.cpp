#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;

	queue <pair<long long, int>> q;
	set<long long> nums;

	q.push({ a,0 });

	while (!q.empty())
	{
		pair<long long, int> top = q.front();
		q.pop();

		if (top.first > b)
			continue;

		if (nums.find(top.first)!=nums.end())
			continue;

		nums.insert(top.first);

		if (top.first == b)
		{
			cout << top.second + 1 << "\n";
			return 0;
		}

		q.push({ top.first * 2,top.second + 1 });
		q.push({ top.first * 10 + 1,top.second + 1 });
	}
	cout << -1 << "\n";
}