#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long pad[101] = { 0,1,1,1,2,2,3,4,5,7,9, };
	for (int i = 9; i < 101; ++i)
	{
		pad[i] = pad[i - 1] + pad[i - 5];
	}
	while (T--)
	{
		int N;
		cin >> N;

		cout << pad[N] << "\n";
	}
}