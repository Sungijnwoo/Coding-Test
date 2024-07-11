#include <iostream>
#include <vector>
using namespace std;

int getBottles(int totalBottles)
{
	int ret = 0;
	while (totalBottles)
	{
		ret += totalBottles % 2;
		totalBottles = totalBottles >> 1;
	}

	return ret;
}

int main()
{
	int N, K, i = 0, ans = 0;
	cin >> N >> K;

	int bottles = getBottles(N);

	while (bottles>K)
	{
		int add = 1 << i;
		if (add > N||add<0)
		{
			cout << -1 << endl;
			return 0;
		}

		if (N & add)
		{
			N += add;
			ans += add;
		}
		++i;
		bottles = getBottles(N);
	}

	cout << ans << endl;

	return 0;
}