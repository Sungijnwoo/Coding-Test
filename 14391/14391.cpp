#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M,ans=0;
	cin >> N >> M;

	vector<vector<int>> paper(N);
	int checkMax = (1 << N * M);
	for (int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j)
		{
			paper[i].push_back((tmp[j] - '0'));
		}
	}

	for (int check = 0; check <checkMax; ++check) 
	{
		int total = 0;
		// row ¸ÕÀú
		for (int i = 0; i < N; ++i)
		{
			int rowsum = 0;
			for (int j = 0; j < M; ++j)
			{
				int idx = i * M + j;
				if (check & (1 << idx))
				{
					rowsum = rowsum * 10 + paper[i][j];
				}
				else
				{
					total += rowsum;
					rowsum = 0;
				}
			}
			total += rowsum;
		}
		

		for (int j = 0; j < M; ++j)
		{
			int colsum = 0;
			for (int i = 0; i < N; ++i)
			{
				int idx = i * M + j;
				if (!(check & (1 << idx)))
				{
					colsum = colsum * 10 + paper[i][j];
				}
				else
				{
					total += colsum;
					colsum = 0;
				}
			}
			total += colsum;
		}


		ans = max(ans, total);
	}
	cout << ans;
}