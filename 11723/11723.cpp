#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL); cout.tie(NULL);

	int M,S=0;
	cin >> M;

	while (M--)
	{
		string op;
		cin >> op;

		if (op == "add")
		{
			int input;
			cin >> input;
			
			S |= (1 << (input - 1));
		}	
		else if (op == "remove")
		{
			int input;
			cin >> input;
			
			S &= ~(1 << (input - 1));
		}	
		else if (op == "check")
		{
			int input;
			cin >> input;
			if ((S & (1<<(input-1))) > 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}	
		else if (op == "toggle")
		{
			int input;
			cin >> input;
		
			S ^= 1 << (input - 1);
		}	
		else if (op == "all")
		{
			S = ~0;
		}
		else
		{
			S = 0;
		}
	}
}