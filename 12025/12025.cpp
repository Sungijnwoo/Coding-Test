#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string password;
	cin >> password;

	long long k, n = 1;
	cin >> k;

	

	vector<int> idx;
	for (int i = 0; i < password.size(); ++i)
	{
		if (password[i] == '1' || password[i] == '6')
		{
			idx.push_back(i);
			password[i] = '1';

			n = n << 1;
		}
		else if (password[i] == '2' || password[i] == '7')
		{
			idx.push_back(i);
			password[i] = '2';

			n = n << 1;
		}
	}

	if (n < k||k<=0)
	{
		cout << -1;
		return 0;
	}
	long long tmp = 1;
	for (int i = 0; (tmp << i) <= (k-1); ++i)
	{
		if ((k-1) & (1 << i))
		{
			int passwordIdx = idx.back();

			if (password[passwordIdx] == '1')
				password[passwordIdx] = '6';
			else
				password[passwordIdx] = '7';
		}
		
		idx.pop_back();
	}

	cout << password;

	return 0;
}