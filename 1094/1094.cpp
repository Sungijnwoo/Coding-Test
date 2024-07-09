#include <iostream>
using namespace std;

int main()
{
	int x, currentStick, stickLen = 64, cnt = 0;
	cin >> x;

	if (x == 64)
	{
		cout << 1 << endl;
		return 0;
	}

	currentStick = stickLen;
	stickLen = 0;
	while (stickLen != x)
	{
		while (stickLen + currentStick > x)
		{
			currentStick = currentStick >> 1;
		}
		stickLen += currentStick;
		++cnt;
	}
	cout << cnt << endl;

	return 0;
}

