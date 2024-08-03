#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> student(M);

	for (int i = 0; i < M; ++i)
	{
		int cnt;
		cin >> cnt;

		for (int j = 0; j < cnt; ++j)
		{
			int proNum;
			cin >> proNum;

			student[i] |= (1 << (proNum-1));
		}
	}

	int caseMax = (1 << M);
	int solveMax = (1 << N) - 1;
	int ans = 11;
	for (int teamCase = 1; teamCase < caseMax; ++teamCase)
	{
		int solveCase = 0;
		int teamCnt = 0;
		for (int push = 0; push < M; ++push)
		{
			if (teamCase & (1 << push))
			{
				solveCase |= student[push];
				++teamCnt;
			}
		}
		if (solveCase == solveMax)
		{
			ans = min(ans, teamCnt);
		}
	}

	if (ans == 11)
		cout << -1;
	else
		cout << ans;
}