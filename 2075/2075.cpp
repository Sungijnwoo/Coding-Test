#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N,ans;
	cin >> N;

	// �켱���� ť�� �̿��� ���
	// �켱���� ť�� ũ�Ⱑ N�� �����ϵ��� �Ͽ� ��� ���� �Է��Ͽ��� �� top�� N��°�� ū ���� �ǵ��� �Ѵ�.
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



	// 2���� �迭�� �����ְ� �� �������� �� idx�� �����ϵ��� ��.(�� �������� �ִ밪 ����)
	// �ִ밪�� �߿��� ���� ū ���� �� idx�� 1�� �ٿ� �� �ִ밪 ������ �� ���� �ִ밪�� ������ ��.
	// �׷��� k��° ū �� �� �ִ� �������� k��° ���� ���ܽ������Ƿ� k+1��° ū ���� �ִ� ������ �ȴ�.
	// N�� �ݺ��ϸ� ���������� ������ ���� N��°�� ���� ū ���� �ȴ�.
	// �׷��� ������ ans�� �����ϴ� ���� �־ �� ���� �� �� �ֵ��� �Ѵ�.
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