#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main()
{

	int N, M;
	cin >> N;
	set<int> tree;
	vector<int> ans;
	while (N--)
	{
		int input;
		cin >> input;
		tree.insert(input);
	}
	cin >> M;
	while (M--)
	{
		int input;
		cin >> input;
		auto it = tree.find(input);

		if (it == tree.end())
			//cout << 0 << " ";
			ans.push_back(0);
		else
			ans.push_back(1);
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}

}