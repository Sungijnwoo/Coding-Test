#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

set<vector<int>> check;

void solve(vector<int>& nums, vector<bool>& visited, vector<int>& current)
{
	if (current.size() == m)
	{
		if (check.end() == check.find(current))
		{
			check.insert(current);
			for (int i = 0; i < m; ++i)
			{
				cout << current[i] << " ";
			}
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		
		current.push_back(nums[i]);

		solve(nums, visited, current);

		visited[i] = false;

		current.pop_back();
	}
}

int main()
{
	cin >> n >> m;

	vector<int> nums;
	vector<bool> visited(n);
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		nums.push_back(input);
	}

	sort(nums.begin(), nums.end());
	
	vector<int> current;
	solve(nums, visited, current);
}