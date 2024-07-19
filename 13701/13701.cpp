#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);



	bitset<33554432> bits;
	int input;
	while (cin >> input)
	{
		if (!bits[input])
		{
			cout << input << " ";
			bits[input] = 1;
		}
	}
}