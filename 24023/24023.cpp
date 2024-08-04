#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int res = 0,s=1;

	for (int i = 1; i <= N; ++i)
	{
		int num;
		cin >> num;

		if ((num | K) != K)
		{
			s = i + 1;
			res = 0;
		}
		else
		{
			res |= num;
			if (res == K)
			{
				cout << s << " " << i << endl;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}