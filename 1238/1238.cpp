#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define INF 1e9

struct edge
{
	int start;
	int end;
	int time;

	bool operator<(const edge e) const
	{
		return this->time > e.time;
	}
};

int main()
{
	int n, m, x;
	cin >> n >> m >> x;

	vector<int> goDis(n + 1,INF);
	vector<int> backDis(n + 1, INF);

	vector<vector<pair<int, int>>> village(n + 1);
	vector<vector<pair<int, int>>> rev_village(n + 1);

	priority_queue<edge> pq;
	priority_queue<edge> rev_pq;


	// x에서 n으로 가는 것은 성공
	for (int i = 0; i < m; ++i)
	{
		int s, e, t;
		cin >> s >> e >> t;

		edge tmp;
		tmp.start = s;
		tmp.end = e;
		tmp.time = t;

		village[s].push_back({ e,t });
		rev_village[e].push_back({ s,t });
	}

	for (int i = 0; i < village[x].size(); ++i)
	{
		pq.push({ x,village[x][i].first,village[x][i].second });
	}

	backDis[x] = 0; 

	while (!pq.empty()) 
	{ 
		edge front = pq.top(); 
		pq.pop(); 

		backDis[front.end] = min(backDis[front.end],front.time);

		for (int i = 0; i < village[front.end].size(); ++i) 
		{
			if (backDis[village[front.end][i].first] == INF)
				pq.push({ front.end,village[front.end][i].first,village[front.end][i].second + backDis[front.end]});
		}
	}

	// 역방향 다익스트라
	for (int i = 0; i < rev_village[x].size(); ++i)
	{
		rev_pq.push({ x,rev_village[x][i].first,rev_village[x][i].second });
	}

	goDis[x] = 0;

	while (!rev_pq.empty())
	{
		edge front = rev_pq.top(); 
		rev_pq.pop();

		goDis[front.end] = min(goDis[front.end], front.time);

		for (int i = 0; i < rev_village[front.end].size(); ++i)
		{
			if (goDis[rev_village[front.end][i].first] == INF)
				rev_pq.push({ front.end,rev_village[front.end][i].first,rev_village[front.end][i].second  + goDis[front.end]});
		}
	}
	// n에서 x로 가는 것은 못구했음.
	/*for (int i = 1; i <= n; ++i)
	{
		if (i == x)
			continue;
		priority_queue<edge> tmp;
		vector<int> toX(n + 1, 0);
		for (int j = 0; j < village[i].size(); ++j)
		{
			tmp.push({ i,village[i][j].first,village[i][j].second });
		}

		while (toX[x] == 0)
		{
			edge front = tmp.top();
			tmp.pop();

			toX[front.end] = toX[front.start] + front.time;



			if (goDis[front.end] != 0)
			{
				toX[x] += goDis[front.end] + toX[front.end];
				break;
			}

			for (int j = 0; j < village[front.end].size(); ++j)
			{
				if (toX[village[front.end][j].first == 0])
					tmp.push({ front.end,village[front.end][j].first,village[front.end][j].second });
			}
		}
		goDis[i] = toX[x];
	}*/



	int mx = 0, ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i == x)
			continue;
		if (mx < goDis[i] + backDis[i])
		{
			mx = goDis[i] + backDis[i];
			ans = i;
		}
	}
	cout << mx << endl;
}