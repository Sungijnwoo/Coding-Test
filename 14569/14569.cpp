#include <iostream>
#include <vector>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	vector<long long> schedules(N);

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;

		for (int j = 0; j < k; ++j)
		{
			int t;
			cin >> t;
			schedules[i] |= ((long long)1 << t);
		}
	}

	cin >> M;

	vector<long long> students(M);
	for (int i = 0; i < M; ++i)
	{
		int p;
		cin >> p;

		for (int j = 0; j < p; ++j)
		{
			int q;
			cin >> q;

			students[i] |= ((long long) 1 << q);
		}

		
	}

	for (int i = 0; i < M; ++i)
	{
		int cnt = 0;
		for (int schedule = 0; schedule < N; ++schedule)
		{
			if ((students[i] & schedules[schedule]) == schedules[schedule])
				++cnt;
		}
		cout << cnt << " ";
	}

	return 0;

}