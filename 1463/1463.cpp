#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> nums(N + 1);
	nums[1] = 0;

	for (int i = 2; i <= N; ++i)
	{
		if (i % 6 == 0)
		{
			nums[i] = min(nums[i / 2], min(nums[i / 3], nums[i - 1])) + 1;
		}
		else if (i % 2 == 0)
		{
			nums[i] = min(nums[i / 2], nums[i - 1]) + 1;
		}
		else if (i % 3 == 0)
		{
			nums[i] = min(nums[i / 3], nums[i - 1]) + 1;
		}
		else
		{
			nums[i] = nums[i - 1] + 1;
		}
	}
	cout << nums[N];
}