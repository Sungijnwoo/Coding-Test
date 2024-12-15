#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main()
{
	int n, k, result=0;
	cin >> n >> k;

	if (n == k)
	{
		cout << 0 << "\n" << 1;
		return 0;
	}
	// 걸린시간 / 방법 갯수
	// vector<pair<int, int>> pos(100001,pair<int,int>(0,0));    

	vector<int> pos(100001);

	// idx, 걸린 시간 
	queue<pair<int,int>> q; 
	q.push({ n,0 }); 
	// pos[n].second = 1;
	pos[n] = 1;
	while (!q.empty())
	{
		int idx = q.front().first;
		int time = q.front().second;



		q.pop();

		if (idx == k) 
			++result; 

		/*if (0 <= idx + 1 && idx + 1 < 100001 && (pos[idx + 1].first == 0 || pos[idx + 1].first == time + 1))
		{
			q.push({ idx + 1, time + 1 });
			pos[idx + 1].first = time + 1;
			++pos[idx + 1].second;
		}
		if (0 <= idx - 1 && idx - 1 < 100001 && (pos[idx - 1].first == 0 || pos[idx - 1].first == time + 1))
		{
			q.push({ idx - 1, time + 1 });
			pos[idx - 1].first = time + 1;
			++pos[idx - 1].second;
		}
		if (0 <= idx * 2 && idx * 2 < 100001 && (pos[idx * 2].first == 0 || pos[idx * 2].first == time + 1))
		{
			q.push({ idx * 2, time + 1 });
			pos[idx * 2].first = time + 1;
			++pos[idx * 2].second;
		}*/

	if (0 <= idx + 1 && idx + 1 < 100001 && (pos[idx + 1]== 0 || pos[idx + 1] == time + 1))
	{
		q.push({ idx + 1, time + 1 });
		pos[idx + 1] = time + 1;
		//++pos[idx + 1].second;
	}
	if (0 <= idx - 1 && idx - 1 < 100001 && (pos[idx - 1] == 0 || pos[idx - 1] == time + 1))
	{
		q.push({ idx - 1, time + 1 });
		pos[idx - 1] = time + 1;
		//++pos[idx - 1].second;
	}
	if (0 <= idx * 2 && idx * 2 < 100001 && (pos[idx * 2] == 0 || pos[idx * 2] == time + 1))
	{
		q.push({ idx * 2, time + 1 });
		pos[idx * 2]= time + 1;
		//++pos[idx * 2].second;
	}
	}


	// cout << pos[k].first << "\n" << pos[k].second;
	cout << pos[k] << "\n" << result;
}