#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;

	vector<int> wordInBits;

	while (N--)
	{
		string input;
		cin >> input;

		wordInBits.push_back(0);

		for (char c : input)
		{
			wordInBits.back() |= (1 << (c - 'a'));
		}
	}

	int memory = (1 << 26) - 1;

	while (M--)
	{
		int op;
		char ch;

		cin >> op >> ch;
		if (op == 1)
		{
			memory ^= (1 << (ch - 'a'));
		}
		else
		{
			memory ^= (1 << (ch - 'a'));
		}

		int cnt = 0;
		for (int i = 0; i < wordInBits.size(); ++i)
		{
			if ((wordInBits[i] & memory) == wordInBits[i])
			{
				++cnt;
			}
		}
		cout << cnt << "\n";
	}
}