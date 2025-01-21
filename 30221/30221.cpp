#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define INF 1e9

struct edge
{
	int start;
	int end;
	int value;
};

int main()
{

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;



	//vector<edge> edges;

	edge edges[10003];

	// vector<int> dis(n+1,INF);

	int dis[5003];
	fill(dis + 1, dis + 5003, INF);

	dis[1] = 0;
	for (int i = 0; i < m; ++i)
	{
		int s, e, a;
		char t;

		cin >> s >> e >> t >> a;

		edge tmp;
		tmp.start = s;
		tmp.end = e;
		if (t == 'b')
			tmp.value = a;
		else
			tmp.value = -a;

		//edges.push_back(tmp);
		edges[i] = tmp;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int src = edges[j].start; int dst = edges[j].end;
			int time = edges[j].value;
			/*if (dis[src]!=INF && dis[dst] > dis[src] + time)
			{
				dis[dst] = dis[src] + time;
			}*/

			dis[dst] = min(dis[dst], dis[src] + time);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (dis[i] < 0)
			cout << i << "\n";
	}
}