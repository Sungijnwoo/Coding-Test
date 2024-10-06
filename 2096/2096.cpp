#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> boardMax(3);
	vector<int> boardMin(3);

	int a, b, c;
	cin >> a >> b >> c;

	boardMax[0] = a;
	boardMax[1] = b;
	boardMax[2] = c;

	boardMin[0] = a;
	boardMin[1] = b;
	boardMin[2] = c;


	for (int i = 1; i < N; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vector<int> tempMax = boardMax;
		vector<int> tempMin = boardMin;
		for (int j = 0; j < 3; ++j)
		{
			if (j == 2)
			{
				boardMax[2] = max(c + tempMax[1], c + tempMax[2]);
				boardMin[2] = min(c + tempMin[1], c + tempMin[2]);

			}
			else if (j == 0)
			{
				boardMax[0] = max(a + tempMax[0], a + tempMax[1]);
				boardMin[0] = min(a + tempMin[0], a + tempMin[1]);

			}
			else
			{
				boardMax[1] = max(b + tempMax[1], max(b + tempMax[0], b+ tempMax[2]));
				boardMin[1] = min(b + tempMin[1], min(b + tempMin[0], b + tempMin[2]));
			}
		}
	}


	cout << max(boardMax[0], max(boardMax[1], boardMax[2])) << endl;

	cout << min(boardMin[0], min(boardMin[1], boardMin[2])) << endl;
}