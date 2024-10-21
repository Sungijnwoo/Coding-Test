#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, T,count=0;
	cin >> N >> M >>T;


	long long mask = 0;

	vector<long long> parties;
	// 진실을 아는 사람 마스킹
	for (int i = 0; i < T; ++i)
	{
		int truth;
		cin >> truth;
		mask = mask | ((long long)1 << truth);
	}

	// 파티마다의 멤버 체크
	for (int i = 0; i < M; ++i)
	{
		long long partyMem = 0;
		int party;
		cin >> party;
		for (int j = 0; j < party; ++j)
		{
			int Mem;
			cin >> Mem;
			partyMem = partyMem | ((long long)1 << Mem);

			
		}
		parties.push_back(partyMem);
	}

	

	while (true)
	{
		int tempCount = 0;
		for (int i = 0; i < parties.size(); ++i)
		{
			if ((mask & parties[i]) == 0)
			{
				++tempCount;
			}
			else
			{
				mask = mask | parties[i];
			}
		}

		if (tempCount == count)
		{
			break;
		}
		else
		{
			count = tempCount;
		}
	}

	cout << count;
}