#include <iostream>
#include <vector>
using namespace std;

int ans = 100000;

void check(vector<pair<int, int>>& house, vector<pair<int, int>>& chi, vector<int> chicDis, vector<int>& visit, int idx, int bound)
{
	if (visit.size() >= bound || idx>= chi.size())
	{
		// 치킨거리 값 적용
		return;
	}

	pair<int, int> current = chi[idx];
	vector<int> AddDis;
	int currentSum = 0;
	for (int i = 0; i < house.size(); ++i)
	{
		int tmp = abs(house[i].first - current.first) + abs(house[i].second - current.second); 

		tmp = min(chicDis[i], tmp);

		AddDis.push_back(tmp);

		currentSum += tmp;
	}

	ans = min(ans, currentSum);

	visit.push_back(idx);
	check(house, chi, AddDis, visit, idx+1, bound);

	visit.pop_back();
	check(house, chi, chicDis, visit, idx+1, bound);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> chi;
	vector<pair<int, int>> house;
	vector<int> chicDis;
	vector<int> visit;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int input;
			cin >> input;
			if (input == 1)
				house.push_back({ i,j });
			else if (input == 2)
				chi.push_back({ i,j });
		}
	}

	chicDis.resize(house.size(),100000);

	check(house, chi, chicDis, visit, 0, m);

	cout << ans;
}