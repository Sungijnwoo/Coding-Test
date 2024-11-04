#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	long double sum = 0;


	vector<pair<int, int>> dots(N);

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;

		dots[i].first = x;
		dots[i].second = y;
	}

	for (int i = 1; i < N - 1; ++i)
	{
		pair<long double, long double> dot1 = dots[0];
		pair<long double, long double> dot2 = dots[i];
		pair<long double, long double> dot3 = dots[i + 1];

		sum += (dot1.first * dot2.second + dot2.first * dot3.second + dot3.first * dot1.second - dot1.second * dot2.first - dot2.second * dot3.first - dot3.second * dot1.first)/2; 
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(sum) << endl;
}