#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, M, ans =0;
	cin >> N >> M;

	int arr[100001];
	int size = 1 << 20;
	bool cache[size];

	int mask = (1 << 20) - 1;

	while (M--)
	{
		int order,i,x;
		cin >> order;

		switch (order)
		{
			case 1:
				cin >> i >> x;
				arr[i] |=(1<<(x-1));
				break;
			case 2:
				cin >> i >> x;
				arr[i] &=~(1<<(x-1));
				arr[i] &= mask;
				break;
			case 3:
				cin >> i;
				arr[i] = arr[i] << 1;
				arr[i] &= mask;
				break;
			case 4:
				cin >> i;
				arr[i] &= mask;
				arr[i] = arr[i] >> 1;
				break;
			default :
				break;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (cache[arr[i]])
			continue;
		++ans;
		cache[arr[i]] = 1;
	}
	cout << ans << endl;
	return 0;
}