#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct doc
{
	int priority;
	int check;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		int N, M, cnt = 0;
		bool isChecked = false;
		cin >> N >> M;
		queue<doc> print;
		vector<int> priorities(10, 0);
		for (int i = 0; i < N; ++i)
		{
			int input;
			cin >> input;
			print.push({ input,i });
			++priorities[input];
		}

		int doc_pri = 9;

		while (priorities[doc_pri] == 0)
		{
			--doc_pri;
		}

		while (!print.empty() || !isChecked)
		{
			doc front = print.front();
			if (front.priority != doc_pri)
			{
				print.push(front);
				print.pop();
			}
			else
			{
				print.pop();
				++cnt;
				--priorities[doc_pri];
				while (priorities[doc_pri] == 0)
				{
					--doc_pri;
				}
				if (front.check == M)
				{
					cout << cnt << endl;
					isChecked = true;
					break;
				}
			}
		}
	}


	return 0;
}