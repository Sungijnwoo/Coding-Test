#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// ���� ���, ���� ���� �����ʰ� 2���� �迭 �����ؼ� Ǫ�� ���� �ӵ��� �� ������
struct Edge;

struct Node
{
	int idx;
	vector<Edge*> edges;
	Node(int _idx)
	{
		idx = _idx;
	}
};

struct Edge
{
	int cost;
	Node* dst;
};

struct dat
{
	int idx;
	int cost;
};
// priority_queue�� ����� ����ü
struct cmp
{
	bool operator()(dat a, dat b)
	{
		return a.cost > b.cost;
	}
};

int main()
{
	int V, E, K;
	cin >> V >> E >> K;

	vector<Node*> graph;
	vector<int> ans(V+1, INT_MAX);

	// graph index, cost
	priority_queue<dat,vector<dat>,cmp> q;

	for (int i = 0; i <= V; ++i)
	{
		graph.push_back(new Node(i));
	}

	for (int i = 0; i < E; ++i)
	{
		int src, dst, cost;
		cin >> src >> dst >> cost;
		Edge* edge = new Edge();
		edge->cost = cost;
		edge->dst = graph[dst];
		graph[src]->edges.push_back(edge);
	}
	q.push({ K, 0 });
	
	while (!q.empty())
	{
		dat top = q.top();
		q.pop();
		int idx = top.idx;
		int cost = top.cost;
		int size = graph[idx]->edges.size();
		
		// ���� �� �۾����� ��쿡�� ���� �����ϰ� ������ ������ ��ȸ
		if (ans[idx] > cost)
		{
			ans[idx] = cost;
			// edge ��ȸ
			for (int i = 0; i < size; ++i)
			{
				q.push({ graph[idx]->edges[i]->dst->idx,graph[idx]->edges[i]->cost + ans[idx]});
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (ans[i] == INT_MAX)
			cout << "INF" << "\n";
		else
			cout << ans[i] << "\n";
	}
}