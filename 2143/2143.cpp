#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T, n, m;
	cin >> T >> n;

	vector<int> sumA, sumB;

	vector<int> A(n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		A[i] = input;
	}

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = i; j < n; ++j)
		{
			sum += A[j];
			sumA.push_back(sum);
		}
	}


	cin >> m;
	vector<int> B(m);
	sum = 0;
	for (int i = 0; i < m; ++i)
	{
		int input;
		cin >> input;
		B[i] = input;
	}

	for (int i = 0; i < m; ++i)
	{
		int sum = 0;
		for (int j = i; j <m; ++j)
		{
			sum += B[j];
			sumB.push_back(sum);
		}
	}

	sort(sumB.begin(), sumB.end()); 

	int answer = 0;
	for (int i = 0; i < sumA.size(); ++i)
	{
		int target = T - sumA[i];

		int low = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
		int high = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin() ;
		answer += (high - low);
	}

	cout << answer;
}