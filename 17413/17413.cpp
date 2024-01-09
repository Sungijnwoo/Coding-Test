#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S, ans;
	getline(cin, S);
	ans = S;
	int stringLength = S.size(), start = 0;
	bool flag = true;
	for (int i = 0; i < stringLength; ++i)
	{
		if (S[i] == '<' || (S[i] == ' ' && flag))
		{
			if (S[i] == '<')
				flag = false;
			// reverse
			int size = i - start;
			for (int j = 0; j < size; ++j)
			{
				ans[i - j - 1] = S[start + j];
			}
			ans[i] = S[i];
			start = i + 1;
		}
		else if (S[i] == '>')
		{
			flag = true;
			start = i + 1;
			ans[i] = S[i];
		}
	}

	if (start != -1)
	{
		int size = stringLength - start;
		for (int j = 0; j < size; ++j)
		{

			ans[stringLength - j - 1] = S[start + j];
		}
	}

	cout << ans << endl;


}