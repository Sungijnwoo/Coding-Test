#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N,ans;
	cin >> N;

	// 우선순위 큐를 이용한 방법
	// 우선순위 큐의 크기가 N을 유지하도록 하여 모든 수를 입력하였을 때 top이 N번째로 큰 수가 되도록 한다.
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int x;
			scanf("%d", &x);
			q.push(x);

			if (q.size() > N)
				q.pop();
		}
	}
	cout << q.top();
	return 0;



	// 2차원 배열에 값을넣고 각 열마다의 행 idx를 추적하도록 함.(각 열마다의 최대값 추적)
	// 최대값들 중에서 가장 큰 값의 행 idx를 1씩 줄여 그 최대값 모음에 그 다음 최대값이 들어가도록 함.
	// 그러면 k번째 큰 수 가 있는 모음에서 k번째 수를 제외시켰으므로 k+1번째 큰 수가 있는 모음이 된다.
	// N번 반복하면 마지막으로 제외한 수가 N번째로 가장 큰 수가 된다.
	// 그렇기 때문에 ans에 제외하는 수를 넣어서 그 값을 알 수 있도록 한다.
	/*vector<vector<int>> table(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			int x;
			scanf("%d", &x);
			table[i][j] = x;
		}
	}

	vector<int> Rowidxs(N, N - 1);
	int cnt = 0, maxColIdx = 0;
	while (cnt < N)
	{
		maxColIdx = 0;
		for (int col = 1; col < N; ++col)
		{
			if (table[Rowidxs[col]][col] > table[Rowidxs[maxColIdx]][maxColIdx])
			{
				maxColIdx = col;
			}
		}
		++cnt;
		ans = table[Rowidxs[maxColIdx]--][maxColIdx];
	}*/

	cout << ans;
}