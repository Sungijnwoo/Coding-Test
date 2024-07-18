#include <iostream>
#include <vector>
using namespace std;

//void Check(vector<int>& alphaCounts, vector<int>& visit, int K, int& ans, int current)
//{
//	if (visit.size() < K)
//	{
//		visit.push_back(current);
//		for (int i = current + 1; i < 26; ++i)
//		{
//			Check(alphaCounts, visit, K, ans, i);
//		}
//		visit.pop_back();
//	}
//
//	else if (visit.size() == K)
//	{
//		int alphaCase = 0;
//		for (int i = 0; i < visit.size(); ++i)
//		{
//			alphaCase += (1 << visit[i]);
//		}
//
//		int ansCount = 0;
//
//		for (int i = 0; i < alphaCounts.size(); ++i)
//		{
//			if ((alphaCounts[i] & alphaCase) == alphaCounts[i])
//				++ansCount;
//		}
//		ans = max(ans, ansCount);
//
//		return;
//	}
//	return;
//}

int next_permutation(int v)
{
	int t = (v | (v - 1));
	return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
	
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, K,ans=0;
	cin >> N >> K;


	vector<int> alphabetCounts;
	vector<int> visit;
	while (N--)
	{
		string word;
		cin >> word;
		
		int mask = 0;
		for (char c : word)
		{
			mask |= (1 << (c - 'a'));
		}
		alphabetCounts.push_back(mask);
	}
	/*int size = 1 << 26;
	


	for (int alphaCase = 1; alphaCase < size; ++alphaCase)
	{
		int ansCount=0,count = 0;
		for (int check = 0; check < 26; ++check)
		{
			if (alphaCase & (1 << check))
				++count;
		}
		if (count == K)
		{
			for (int i = 0; i < alphabetCounts.size(); ++i)
			{
				if ((alphabetCounts[i] & alphaCase) == alphabetCounts[i])
					++ansCount;
			}
			ans = max(ans, ansCount);
		}
		
	}*/
	/*for (int i = 0; i < 26; ++i)
	{
		Check(alphabetCounts, visit, K, ans, i);
	}*/

	for (int i = (1 << K) - 1; (i >> 26) == 0; i = next_permutation(i))
	{
		int ansCount = 0;
		for (int j = 0; j < alphabetCounts.size(); ++j)
		{
			if ((alphabetCounts[j] & i) == alphabetCounts[j])
				++ansCount;
		}
		ans = max(ans, ansCount);
	}



	cout << ans;
}