#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, R, X;

int ans = 0;

const int MAX = 15;


void Check(vector<int>& arr, int start, int current, int sum, int cnt)
{
	if (current == N)
	{
		return;
	}
	Check(arr, start, current + 1, sum,cnt);

	sum += arr[current];
	if ((arr[current] - arr[start] >= X)&&(sum>=L)&&(sum<=R))
	{
		++ans;
	}
	
	Check(arr, start, current + 1, sum,cnt+1);
}

int main()
{
	cin >> N >> L >> R >> X;
	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; ++i)
	{
		Check(arr, i, i+1, arr[i],1);
	}
	

	

	cout << ans << endl;
	return 0;
}