#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1024

int main()
{
	string L, K;
	cin >> L >> K;

	int l = 0, k = 0;
	for (int i = 0; i < L.size(); ++i)
	{
		if (L[i]=='1')
		{
			l += (1 << (L.size() - i - 1));
		}
	}

	for (int i = 0; i < K.size(); ++i)
	{
		if (K[i] == '1')
		{
			k += (1 << (K.size() - i - 1));
		}
	}

	vector<bool> visited(MAX);
	queue<pair<int, int>> q;
	q.push({ l,0 });

	while (!q.empty())
	{
		int currentNum = q.front().first;
		int currentCnt = q.front().second;
		if (currentNum == k)
		{
			cout << currentCnt;
			break;
		}
		q.pop();
		if ((currentNum+1)<MAX&&!visited[currentNum + 1])
		{
			visited[currentNum + 1]=1;
			q.push({ currentNum + 1,currentCnt + 1 });
		}
		if ((currentNum-1)>=0&&!visited[currentNum - 1]) 
		{
			visited[currentNum - 1] = 1;
			q.push({ currentNum - 1,currentCnt + 1 });
		}
		for (int i = 1; (1<<i) <= currentNum; ++i)
		{
			int pushNum = currentNum ^ (1 << (i-1));
			if (!visited[pushNum])
			{
				visited[pushNum] = 1;
				q.push({ pushNum,currentCnt + 1 });
			}
		}
	}
}