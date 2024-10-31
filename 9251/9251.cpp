#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int result = 0;
	string a, b;
	cin >> a >> b;
	vector<vector<int>> commons(a.size() + 1, vector<int>(b.size() + 1, 0));



	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				commons[i][j] = commons[i - 1][j - 1] + 1;
			}
			else
			{
				commons[i][j] = max(commons[i - 1][j], commons[i][j - 1]);
			}
			result = max(result, commons[i][j]);
		}
	}

	cout << result << endl;
}