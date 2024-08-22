#include <iostream>
using namespace std;

int main()
{
	long long N, ans=0,three=1;
	cin >> N;
	int idx = 0;
	while (N >= ((long long)1<<idx))
	{
		if (N & ((long long)1 << idx))
			ans += three;
		++idx;
		three *= 3;
	}

	cout << ans;
}