#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct home
{
	int src;
	int des;
	int cost;

	bool operator<(const home other) const
	{
		if (this->cost == other.cost)
			return this->src < other.src;

		return this->cost > other.cost;
	}
};

vector<int> ufData;
int unionCount = 0;



int find(int a)
{
	if (ufData[a] == a) return a;
	return ufData[a] = find(ufData[a]);
}

bool setUnion(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot) return false;
	ufData[bRoot] = aRoot;
	--unionCount;
	return true;
}
//struct uf
//{
//	vector<int> ufData;
//	int unionCount = 0;
//
//	void setUnion(int a, int b)
//	{
//		if (ufData[a] == ufData[b])
//			return;
//		setUnion(a, ufData[b]);
//		ufData[b] = ufData[a];
//	}
//
//	bool isUnion(int a, int b)
//	{
//		return ufData[a] == ufData[b];
//	}
//
//	uf(int size)
//	{
//		unionCount = size;
//		for (int i = 0; i <= size; ++i)
//		{
//			ufData.push_back(i);
//		}
//	}
//};

int main()
{
	int N, M, answer = 0;
	cin >> N >> M;

	for (int i = 0; i <= N; ++i)
		ufData.push_back(i);

	unionCount = N;

	priority_queue < home> pq;


	for (int i = 0; i < M; ++i)
	{
		int src, des, cost;
		cin >> src >> des >> cost;

		pq.push({ src,des,cost });
	}



	while (!pq.empty())
	{
		if (unionCount == 2)
			break;

		home tmp = pq.top();

		pq.pop();

		if (setUnion(tmp.src, tmp.des))
		{
			answer += tmp.cost;
		}
	}

	cout << answer << endl;
}