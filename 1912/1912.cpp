#include <iostream>
using namespace std;

int main()
{
	int n,ans;
	cin >> n;

	int nums[100000];

	cin >> nums[0];

	ans = nums[0];

	for (int i = 1; i < n; ++i)
	{
		cin >> nums[i];
		nums[i] = max(nums[i], nums[i - 1]+nums[i]);
		ans = max(ans, nums[i]);
	}
	cout << ans;
}