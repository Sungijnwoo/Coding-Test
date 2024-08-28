#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void solve(vector<int>& nums,vector<bool>& visited, vector<int>& current, int idx)
{
	if (idx >= m)
	{
		for (int i = 0; i < current.size(); ++i)
		{
			cout << current[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
			continue;
		
		current.push_back(nums[i]);
		visited[i] = true;

		solve(nums, visited, current, idx + 1);

		current.pop_back();
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<int> nums(n);
	vector<int> current;
	vector<bool> visited(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());


	solve(nums, visited,current, 0);
}