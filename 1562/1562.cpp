#include <iostream>
#include <vector>
using namespace std;

#define DIV 1000000000
//
//int check(int n, int idx, int current)
//{
//	if (current == -1 || current == 10)
//		return 0;
//	if (idx == n)
//		return 1;
//
//	int result = 0;
//	result = (result + check(n, idx + 1, current - 1)) % DIV;
//	result = (result + check(n, idx + 1, current + 1)) % DIV;
//
//
//	return result;
//
//}

int cal(vector<vector<vector<int>>>& check, int idx, int current, int mask,int n) 
{
	int& ref = check[idx][current][mask];
	if (ref) return ref; 
	
	if (idx == n)
	{
		if (mask == (1 << 10) - 1)
			return 1;
		else
			return 0;
	}

	if (current < 9)
	{
		ref += cal(check, idx + 1, current + 1, mask | (1 << current + 1),n);
		ref %= DIV; 
	}
	if (current>0)
	{
		ref += cal(check, idx + 1, current - 1, mask | (1 << current - 1),n);
		ref %= DIV;
	}

	return ref;
}

int main()
{
	int n;
	cin >> n;

	//int result = 0;

	//for (int i = 1; i <= 9; ++i)
	//{
	//	result = (result + check(n, 1, i)) % DIV;
	//}

	//cout << result;

	vector<vector<vector<int>>> check(n + 1, vector<vector<int>>(10, vector<int>(1 << 10)));
	

	int result = 0;
	for (int i = 1; i <= 9; ++i)
	{
		result += cal(check, 1, i, 1 << i, n);
		result %= DIV;
	}

	cout << result;
}
