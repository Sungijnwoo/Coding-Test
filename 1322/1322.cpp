#include<iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned long long X, K;
	cin >> X >> K;
	unsigned long long intMax = (1 << 63) - 1;

	vector<int> indexs;
	unsigned long long mask = 1;
	unsigned long long Y = intMax & (~X);
	for (int i = 0; i < 64; ++i)
	{
		if (Y & (mask << i))
			indexs.push_back(i);
	}

	
	unsigned long long ans = 0;
	unsigned long long adds = 1;
	for (int i = 0; i < indexs.size(); ++i)
	{
		if ((adds << i) > K)
			break;
		if (K & (adds << i))
		{
			ans += (adds << indexs[i]);
		}
		
	}
	cout << ans << endl;



}