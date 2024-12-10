#include <iostream>
#include <vector>
using namespace std;


// ������ n/2
// �� ���� n/4
// �⺻ �ﰢ�� n/3 ��

// �������� �Ű������� �־��

void dotPrint(vector<string>& stars, int line, int size, int pos)
{
	if (size < 3)
		return;
	string tmp = "";

	for (int i = 0; i < size; ++i)
		tmp += " ";
	if (!pos)
	{
		for (int i = 0; i < size; ++i)
		{
			stars[line + i] += tmp;
		}
	}

	if (size == 3)
	{
		int n = stars.size();

		int pad = n - line; 

		string top;
		string mid;
		string bot;


		top += "  *  ";
		mid += " * * ";
		bot += "*****";

		
		stars[line] += top;
		stars[line + 1] += mid;
		stars[line + 2] += bot; 
	}
	
	

	
	dotPrint(stars, line, size / 2,0);
	
	dotPrint(stars, line + size/2, size / 2, 1);
	

	dotPrint(stars, line + size/2, size / 2, 2);

	if (!pos)
	{
		for (int i = 0; i < size; ++i)
		{
			stars[line + i] += tmp;
		}
	}

	if (pos == 1)
	{
		for (int i = 0; i < size; ++i)
		{
			stars[line + i] += " ";
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<string> stars(n,"");


	dotPrint(stars, 0, n, 4);

	for (string st : stars)
	{
		cout << st << "\n";
	}
}