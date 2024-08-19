#include <iostream>
#include <bitset>
using namespace std;

long long N;




int main()
{
	cin >> N;
	
	long long M = 1;

	while (M <= N)
	{
		M = M << 1;
	}
	M = M - 1;

	if (M == N)
		cout << 1 << " " << N;
	else
	{
		cout << 2 << " " << (M ^ N) << " " << N;
	}
}