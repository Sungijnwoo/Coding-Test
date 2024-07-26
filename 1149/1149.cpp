#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int ave[3][1000];

	cin >> ave[0][0] >> ave[1][0] >> ave[2][0];

	for (int i = 1; i < N; ++i)
	{
		int R, G, B;
		cin >> R >> G >> B;

		ave[0][i] = min(ave[1][i - 1], ave[2][i - 1]) + R;
		ave[1][i] = min(ave[0][i - 1], ave[2][i - 1]) + G;
		ave[2][i] = min(ave[0][i - 1], ave[1][i - 1]) + B;
	}

	cout << min(ave[0][N - 1], min(ave[1][N - 1], ave[2][N - 1]));
}