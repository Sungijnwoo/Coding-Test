#include <iostream>
#include <unordered_set>
using namespace std;


int main()
{
	string str;
	cin >> str;
	unordered_set<string> hash;

	for (int i = start; i < str.size(); ++i)
	{
		for (int j = 1; i + j <= str.size(); ++j)
		{
			hash.insert(str.substr(start, end));
		}
	}

	cout << hash.size() << endl;
}