#include <iostream>
#include <vector>
using namespace std;

struct wineCount
{
	int zero;
	int first;
	int second;
};

int main()
{
	int n;
	cin >> n;

	vector<wineCount> wines(n);


	for (int i = 0; i < n; ++i)
	{
		int wine;
		cin >> wine;

		if (i == 0)
		{
			wines[i].zero = 0;
			wines[i].first = wine;
			wines[i].second = 0;
		}
		else if (i == 1)
		{
			wines[i].zero = wines[i - 1].first;
			wines[i].first = wine;
			wines[i].second = wine + wines[i - 1].first;
		}
		else
		{
			wines[i].zero = max(wines[i - 1].first, max(wines[i - 1].second,wines[i-1].zero));
			wines[i].first = wine + max(wines[i - 2].first,max(wines[i-2].second,wines[i-1].zero));
			wines[i].second = wine + wines[i - 1].first;
		}
	}

	if (n == 1)
	{
		cout << wines.back().first;
	}
	else
	{
		int ans = max(wines[n - 2].first, max(wines[n - 2].second, max(wines[n - 1].first, wines[n - 1].second)));

		cout << ans;
	}
}

// 0   100 200 200 200 300
// 100 100 100 200 300 300
// 0   200 100 100 300 400