#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	string bomb;

	string out; 
	vector<int> count;

	count.push_back(0);

	cin >> input;
	cin >> bomb;

	int idx = 0;

	for (char c : input)
	{
		out += c;

		int lastBombIdx = count.back();

		count.push_back(0);
		if (c == bomb[lastBombIdx])
		{
			count.back() = (lastBombIdx + 1);
			// ��ź ���ڿ��� ������
			if (lastBombIdx == bomb.length()-1)
			{
				// �׸�ŭ ����
				for (int i = 0; i <= lastBombIdx; ++i)
				{
					out.pop_back();
					count.pop_back();
				}

				
			}
			continue;
		}
		else if (c == bomb.front())
		{
			count.back() = 1;
		}

	}
	if (out.empty())
		out = "FRULA";
	cout << out;
}