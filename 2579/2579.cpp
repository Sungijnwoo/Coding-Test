#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	pair<int,int> stairs[300];
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if (i == 0)
		{
			stairs[i].first = input;
			stairs[i].second = 0;
		}
		else if (i == 1)
		{
			stairs[i].first = input;
			stairs[i].second = input + stairs[i-1].first;
		}
		else
		{
			stairs[i].first = input + max(stairs[i - 2].first,stairs[i-2].second);
			stairs[i].second = input + stairs[i - 1].first;
		}
	}
	cout << max(stairs[n - 1].first, stairs[n - 1].second) << endl;

}