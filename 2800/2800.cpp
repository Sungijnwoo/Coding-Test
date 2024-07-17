#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	string input;
	// vector<string> ans;
	vector<int> stack;
	vector<pair<int, int>> bracketCache;
	int check = 0;

	set<string> ans1;


	cin >> input;

	int size = input.size();
	int bracketCacheIdx = 0;
	for (int i = 0; i < size; ++i)
	{
		if (input[i] == '(')
		{
			check = check << 1;
			++check;
			stack.push_back(i);
		}
		else if (input[i] == ')')
		{
			bracketCache.push_back({ stack.back(),i });
			stack.pop_back();
		}
	}

	if (check == 0)
	{
		ans.push_back(input);
	}

	for (int i = 1; i <= check; ++i)
	{
		string temp = input;
		int k = 0;
		int l = temp.size();
		for (int j = 0; j < bracketCache.size(); ++j)
		{
			if (i & (1 << j))
			{
				temp[bracketCache[j].first] = '.';
				temp[bracketCache[j].second] = '.';

				/*temp.erase(temp.begin() + bracketCache[j].second);
				temp.erase(temp.begin() + bracketCache[j].first);*/
				/*int cnt = 0;
				for (; k < temp.size(); ++k)
				{
					if (temp[k] == '(')
					{
						if (++cnt == j + 1)
						{
							temp.erase(temp.begin() + k);
							break;
						}
					}
				}
				cnt = 0;
				for (; l >= 0; --l)
				{
					if (temp[l] == ')')
					{
						if (++cnt == j + 1)
						{
							temp.erase(temp.begin() + l);
							break;
						}
					}
				}*/


			}
		}

		for (auto iter = temp.begin(); iter != temp.end(); iter++)
		{
			if (*iter == '.')
			{
				temp.erase(iter);
				iter--;
			}
		}

		// ans.push_back(temp);
		ans1.insert(temp);

	}

	/*sort(ans.begin(), ans.end());

	for (string str : ans)
	{
		cout << str << "\n";
	}*/

	for (string str : ans1)
	{
		cout << str << "\n";
	}

	return 0;
}
