#include <iostream>
#include <vector>
using namespace std;

int ansMax = -(1 << 30), ansMin = (1 << 30);

void Calc(vector<int>& nums, vector<int> ops, int idx,int operand)
{
	if (idx == nums.size())
	{
		ansMax = max(ansMax, operand);
		ansMin = min(ansMin, operand);
	}

	for (int i = 0; i < 4; ++i)
	{
		vector<int> tempOps = ops;
		if (tempOps[i])
		{
			--tempOps[i];
			if (i == 0)
			{
				int add = operand + nums[idx];
				Calc(nums, tempOps, idx + 1, add);
			}
			else if (i == 1)
			{
				int sub = operand - nums[idx];
				Calc(nums, tempOps, idx + 1, sub);

			}
			else if (i == 2)
			{
				int mul = operand * nums[idx];
				Calc(nums, tempOps, idx + 1, mul);

			}
			else
			{
				int div = operand / nums[idx];
				Calc(nums, tempOps, idx + 1, div);

			}
		}
	}

}

int main()
{
	int N;
	cin >> N;
	
	vector<int> nums;
	vector<int> ops(4);

	while (N--)
	{
		int input;
		cin >> input;
		nums.push_back(input);
	}

	for (int i = 0; i < 4; ++i)
	{
		int input;
		cin >> input;
		ops[i] = input;
	}

	Calc(nums, ops, 1, nums[0]);

	cout << ansMax << "\n" << ansMin;

	return 0;
}