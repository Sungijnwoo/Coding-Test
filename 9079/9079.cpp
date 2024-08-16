#include <iostream>
#include <bitset>
using namespace std;


int main()
{
	bitset<9> flip[8];

	flip[0] = 7;
	flip[1] = flip[0] << 3;
	flip[2] = flip[1] << 3;
	flip[3][0] = 1; flip[3][3] = 1; flip[3][6] = 1;
	flip[4] = flip[3] << 1;
	flip[5] = flip[4] << 1;
	flip[6][0] = 1; flip[6][4] = 1; flip[6][8]=1;
	flip[7][2] = 1; flip[7][4] = 1; flip[7][6] = 1;

	int T;
	cin >> T;

	while (T--)
	{
		bitset<9> coins;

		for (int i = 0; i < 9; ++i)
		{
			char c;
			cin >> c;
			if (c == 'H')
			{
				coins[i] = 1;
			}
		}

		int res = 10;
		for (int i = 0; i < (1 << 8); ++i)
		{
			int count = 0;
			bitset<9> temp = coins;
			for (int j = 0; j < 8; ++j)
			{
				if (i & (1 << j))
				{
					temp ^= flip[j];
					++count;
				}
			}


			if (temp.all()|| temp.none())
			{
				res = min(res, count);
			}
		}

		if (res == 10)
			cout << -1 << endl;
		else
		{
			cout << res << endl;
		}


	}
}