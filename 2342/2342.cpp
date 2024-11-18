#include <iostream>
#include <vector>
using namespace std;

int mv[5][5] = { {0,2,2,2,2},{0,1,3,4,3},{0,3,1,3,4},{0,4,3,1,3},{0,3,4,3,1} };
int memo[5][5][100000] = { 0, };
vector<int> input;

int dp(int left, int right, int idx)
{
	if (idx == input.size())
		return 0;

	if (memo[left][right][idx])
		return memo[left][right][idx];

	return memo[left][right][idx]= min(dp(input[idx], right, idx + 1) + mv[left][input[idx]], dp(left, input[idx], idx + 1) + mv[right][input[idx]]);

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	while (true)
	{
		int num;
		cin >> num;

		if (num == 0)
			break;

		input.push_back(num);
	}

	cout << dp(0, 0, 0);

}