#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000

typedef struct Mxheap
{
	int heap[MAX + 1];
	int cnt = 0;

	bool isEmpty()
	{
		return cnt == 0;
	}

	void push(int x)
	{
		heap[++cnt] = x;
		int cur = cnt;

		while (cur > 1)
		{
			int next = cur / 2;

			if (x > heap[next])
			{
				heap[cur] = heap[next];
				cur = next;
			}
			else
			{
				break;
			}
		}
		heap[cur] = x;
	}

	int pop()
	{
		int result = heap[1];
		int x = heap[cnt--];
		int cur = 1;

		while (2*cur <= cnt)
		{
			int next;
			if (cnt<cur * 2 + 1 || heap[cur * 2]>heap[cur * 2 + 1])
			{
				next = cur * 2;
			}
			else
			{
				next = cur * 2 + 1;
			}

			if (x < heap[next])
			{
				heap[cur] = heap[next];
				cur = next;
			}
			else
			{
				break;
			}
		}
		heap[cur] = x;
		return result;
	}
};

int main()
{
	int N;
	vector<int> ans;
	/*priority_queue<int> maxheap;
	cin >> N;

	while (N--)
	{
		int input;
		cin >> input;

		if (input)
		{
			maxheap.push(input);
		}
		else
		{
			if (maxheap.empty())
				ans.push_back(0);
			else
			{
				ans.push_back(maxheap.top());
				maxheap.pop();

			}
		}
	}*/

	Mxheap mx;
	//cin >> N;
	scanf("%d", &N);
	while (N--)
	{
		int a;
		//cin >> a;
		scanf("%d", &a);

		if (a)
		{
			mx.push(a);
		}
		else
		{
			if (mx.isEmpty())
				ans.push_back(0);
			else
				ans.push_back(mx.pop());
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		// cout << ans[i] << " ";
		printf("%d", ans[i]);
		printf(" ");
	}
}