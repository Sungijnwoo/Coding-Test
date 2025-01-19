#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9

// �������� ��� ������ ����� ���¸� ���� �ʴ� ��쵵 �ִ�.
// �� ��� �������� ������ ���·� Ǯ�� ������ ������
// ��ȸ�ϴ� �������� dis[v]==INF �� ��쿡 �湮���� �ʴ� ���� �ƴ϶�
// �Ȱ��� �湮�ؼ� �ּҰ� ������ Ȯ���ϰԵǸ�
// �Ÿ��� ������ �־ �湮���� ���Ѱ� �ƴ� ������ �Ÿ���ŭ ������ ��尡 �ȴ�
// ��, ��� ������ ����� ���°� �ȴ�.
// �׷��� �������� ������ ���¿��� ������ �ذ�ȴ�.
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