#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9

// 문제에서 모든 정점이 연결된 상태를 주지 않는 경우도 있다.
// 이 경우 시작점을 고정한 상태로 풀면 문제가 되지만
// 순회하는 과정에서 dis[v]==INF 인 경우에 방문하지 않는 것이 아니라
// 똑같이 방문해서 최소값 갱신을 확인하게되면
// 거리가 무한히 멀어서 방문하지 못한게 아닌 무한한 거리만큼 떨어진 노드가 된다
// 즉, 모든 정점이 연결된 상태가 된다.
// 그래서 시작점이 고정된 상태여도 문제가 해결된다.
// https://www.acmicpc.net/board/view/72995

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		bool isCycle = false;

		int n,m,w;
		cin >> n >> m >> w;

		vector<vector<int>> world(n+1,vector<int>(n+1,INF)); 

		vector<vector<int>> edges;  

		vector<int> dis(n+1,INF); 
		for (int i = 0; i < m; ++i)
		{
			int s, e, t;
			cin >> s >> e >> t;

			edges.push_back({ s,e,t });
			if(s!=e)
				edges.push_back({ e,s,t });
		}

		for (int i = 0; i < w; ++i)  
		{
			int s, e, t;
			cin >> s >> e >> t;

			edges.push_back({ s,e,-t });
		}

		int st = edges[0][0];
		dis[st] = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < edges.size(); ++j)
			{
				int cur = edges[j][0];
				int next = edges[j][1];
				int time = edges[j][2];

				if (dis[next] > dis[cur] + time) 
				{
					dis[next] = dis[cur] + time;
					if (i == n-1)
						isCycle = true;
				}
			}
		}

		if (isCycle)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}