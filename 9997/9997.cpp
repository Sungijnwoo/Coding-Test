#include <iostream>
#include <vector>
using namespace std;

int alphaIdxMax = 'z' - 'a' + 1;
int N;
int alpha[25];
int ans = 0;


void recur(int currentArrayIdx, int res)
{
	if (currentArrayIdx == N)
	{
		if (res == (1 << alphaIdxMax) - 1)
			++ans;
		return;
	}

	recur(currentArrayIdx + 1, res);
	recur(currentArrayIdx + 1, res | alpha[currentArrayIdx]);
}

int main()
{
	cin >> N;


	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;

		for (char c : input)
		{
			alpha[i] |= (1 << (c - 'a'));
		}
	}

	recur(0, 0);

	cout << ans;
}