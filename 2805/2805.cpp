#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, ans, blade_height, hi, lo=0;
	cin >> N >> M;
	
	vector<int> trees(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> trees[i];
		hi = max(hi, trees[i]);
	}

	long long res;
	
	while (lo <= hi)
	{
		res = 0;

		blade_height = (lo + hi) / 2;

		for (int i = 0; i < N; ++i)
		{
			res += max(0, trees[i] - blade_height);
		}

		/**
		* 정답이 바로 바로 정해졌을 때 좀 더 느릴거라고 생각했으나 큰 차이가 없었다.
		if (res == M)
		{
			ans=blade_height;
		
			lo = blade_height + 1;
		}
		else
		{
			hi = blade_height - 1;
		}
		*/

		if (res == M)
		{
			cout << blade_height;
			return 0;
		}
		else if(res>M)
		{
			lo = blade_height + 1;
		}
		else
		{
			hi = blade_height - 1;
		}
	}
	
	if (res < M)
		cout << blade_height - 1;
	else
		cout << blade_height;
}