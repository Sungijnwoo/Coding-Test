#include <iostream>
#include <vector>
using namespace std;

// 유니온 n 파인드에서 마지막에 그은 두 선이 둘다 이미 포함되어있는 경우?
int getParent(vector<int>& uf, int idx)
{
	if (uf[idx] == idx)
		return idx;

	return uf[idx] = getParent(uf, uf[idx]);
}

bool setUF(vector<int>& uf, int idx1, int idx2)
{
	int root1 = getParent(uf, idx1);
	int root2 = getParent(uf, idx2);

	if (root1 == root2)
		return false;

	uf[root2] = root1;
	 return true;
}



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, ans=0;
	cin >> n >> m;

	vector<int> uf(n + 1);
	for (int i = 0; i <= n; ++i)
	{
		uf[i] = i; 
	}

	

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (!setUF(uf,a,b))
		{
			ans = i + 1;
			break;
		}
	}

	cout << ans << endl;
}