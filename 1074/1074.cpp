#include <iostream>
using namespace std;

int N, r, c, ans = 0;


int main()
{
	cin >> N >> r >> c;

	while (N-- > 0)
	{
		int tmp = 1 << N;
		int count = 0;
		if (r >= tmp)
		{
			r -= tmp;
			count += 2;
		}
		if (c >= tmp)
		{
			c -= tmp;
			count += 1;
		}

		ans += tmp * tmp * count;
	}

	cout << ans;
}