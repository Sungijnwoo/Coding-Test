#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[4000];
int b[4000];
int c[4000];
int d[4000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	// vector<int> a(n);
	// vector<int> b(n);
	// vector<int> c(n);
	// vector<int> d(n);

	vector<int> ab;
	vector<int> cd;



	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}

	long long ans = 0;
	sort(cd.begin(), cd.end());

	for (int i = 0; i < ab.size(); ++i)
	{
		int current = ab[i];

		int low = lower_bound(cd.begin(), cd.end(), -current) - cd.begin();
		if (cd[low] == -current)
		{
			int high = upper_bound(cd.begin(), cd.end(), -current) - cd.begin();
			ans += high - low;
		}
	}

	cout << ans;
}