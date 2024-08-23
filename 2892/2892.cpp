#include <iostream>
#include <string>
using namespace std;

// '.' : 46
// ' ' : 32
int main()
{
	int N;
	cin >> N;
	string ans = "";
	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;

		
		
		int	hex = stoi(input, nullptr, 16);
		/*hex += ((input / 100) << 8);
		hex += (((input % 100) / 10) << 4);
		hex+=(input % 10);
		*/
	
		bool bIsChar = true;
		for (int key = '0'; key <= '9'; ++key)
		{
			int result = hex ^ key;
			if (result == '.' ||result == ' ')
			{
				bIsChar = false;
				break;
			}
		}
		if (bIsChar)
			ans+= '-';
		else
			ans+= '.';
	}
	
	cout << ans << endl;
}