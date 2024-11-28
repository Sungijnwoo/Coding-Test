#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int find(vector<int>& vec, int idx)
{
	if (vec[idx] == idx)
		return idx;
	return vec[idx] = find(vec, vec[idx]);
}

bool setUF(vector<int>& vec, int idx1, int idx2)
{
	int root1 = find(vec,idx1);
	int root2 = find(vec,idx2);

	if (root1 == root2)
		return false;

	if (root1 < root2)
	{
		vec[root2] = root1;
	}
	else
	{
		vec[root1] = root2;
	}

	return true;
}

int main()
{
	int g, p;
	cin >> g >> p;

	vector<int> gates(g + 1);
	vector<int> planes(p + 1);
	
	for (int i = 1; i <= g; ++i)
	{
		gates[i] = i;
	}
	
	int ans = 0;
	for (int i = 1; i <= p; ++i)
	{
		int plane;
		cin >> plane;

		int dock = find(gates, plane);
		if (dock == 0)
			break;
		gates[dock] = dock - 1;

		++ans; 
		
	}

	cout << ans; 
}