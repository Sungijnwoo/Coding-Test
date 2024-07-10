#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 2000000000

int calTaste(vector<pair<int, int>>& ingre, int idx, int ans, int sour, int bitter)
{
	if (idx >= ingre.size())
	{
		if (sour == 1 && bitter == 0)
		{
			return INT_MAX;
		}
		return min(ans, abs(sour - bitter));
	}
	ans = min(ans, calTaste(ingre, idx + 1, ans, sour, bitter));
	ans = min(ans, calTaste(ingre, idx + 1, ans, sour * ingre[idx].first, bitter + ingre[idx].second));

	return ans;
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> arr;
	while (N--)
	{
		int sour, bitter;
		cin >> sour >> bitter;
		arr.push_back({ sour,bitter });
	}

	int ans = calTaste(arr, 0, INT_MAX, 1, 0);

	cout << ans << endl;
}