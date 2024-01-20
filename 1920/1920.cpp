#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,M;
	cin >> N;
	vector<int> array(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> array[i];
	}

	sort(array.begin(), array.end());
	cin >> M;
	
	for (int i = 0; i < M; ++i)
	{
		int num,mid,left =0,right=N-1;
		cin >> num;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (array[mid] == num)
			{
				cout << 1 << "\n";
				break;
			}
			else if (array[mid] < num)
			{
				left = mid+1;
			}
			else
			{
				right = mid-1;
			}
		}
		if (left > right)
		{
			cout << 0 << "\n";
		}
	}
}