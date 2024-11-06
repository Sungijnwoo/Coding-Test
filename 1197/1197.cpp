#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct nodeEdge
{
	int src;
	int des;
	int cost;

	bool operator< (const nodeEdge other) const
	{
		return this->cost > other.cost;
	}
};

int getParent(vector<int>& uf, int node)
{
	if (node == uf[node])
		return node;
	return uf[node] = getParent(uf, uf[node]);
}

bool setUnion(vector<int>& uf, int node1, int node2)
{
	int root1 = getParent(uf, node1);
	int root2 = getParent(uf, node2);

	if (root1 == root2)
		return false;

	uf[root2] = root1;
	return true;
}

int main()
{
	int V, E, answer=0;
	cin >> V >> E;

	vector<int> uf(V+1);
	priority_queue<nodeEdge> pq;

	for (int i = 0; i <= V; ++i)
	{
		uf[i] = i;
	}

	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		pq.push({ a,b,c });
	}

	while (!pq.empty())
	{
		nodeEdge tmp = pq.top();
		pq.pop();

		if (setUnion(uf, tmp.src, tmp.des))
		{
			answer += tmp.cost;
		}
	}

	cout << answer << endl;
}