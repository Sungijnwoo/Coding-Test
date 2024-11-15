#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> players(N);
	vector<int> scores(1000001,0);
	vector<bool> nums(1000001,false); 

	for (int i = 0; i < N; ++i)
	{
		cin >> players[i];

		nums[players[i]] = true;
	}

	
	for (int i = 0; i < N; ++i)
	{
		int current = players[i];

		while (current <= 1000000)
		{
			if (nums[current])
			{
				++scores[players[i]];
				--scores[current];
			}
			current += players[i];
		}
	}


	for (int i = 0; i < N; ++i)
	{
		cout << scores[players[i]] << " ";
	}
}