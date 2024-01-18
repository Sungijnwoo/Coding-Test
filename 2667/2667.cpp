#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

// cout<<endl;의 오버헤드가 생각보다 크다

// BFS를 사용한 방법
struct Pos
{
	int x;
	int y;
};

int main()
{
	int N;
	cin >> N;
	vector<string> map;
	vector<int> ans;
	for (int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		map.push_back(tmp);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == '1')
			{
				queue<Pos> q;
				q.push({ i,j });
				int res = 0;
				while (!q.empty())
				{
					Pos top = q.front();
					q.pop();
					if (top.x>=0&&top.y>=0&&top.x<N&&top.y<N&&map[top.x][top.y] == '1')
					{
						res += 1;
						map[top.x][top.y] = '0';
						q.push({ top.x + 1,top.y });
						q.push({ top.x,top.y + 1 });
						q.push({ top.x - 1,top.y });
						q.push({ top.x,top.y - 1});
					}
				}
				ans.push_back(res);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	
	for (auto iter = ans.begin(); iter != ans.end(); iter++)
	{
		cout << *iter << "\n";
	}

}

// DFS를 이용한 방법
//int DFS(vector<string>& map,int size, int x, int y)
//{
//	if (x < 0 || y < 0 || x >= size || y >= size||map[x][y]=='0')
//		return 0;
//	int result = 1;
//	map[x][y] = '0';
//	result +=DFS(map, size, x + 1, y);
//	result +=DFS(map, size, x - 1, y);
//	result +=DFS(map, size, x, y + 1);
//	result +=DFS(map, size, x, y - 1);
//
//	return result;
//}
//
//int main()
//{
//	int N;
//	vector<string> map;
//	multiset<int> ans;
//	
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		string val;
//		cin >> val;
//		map.push_back(val);
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			if (map[i][j] == '1')
//			{
//				int result = DFS(map, N, i, j);
//				ans.insert(result);
//			}
//		}
//	}
//	cout << ans.size() << endl;
//	for (auto iter = ans.begin(); iter!=ans.end(); iter++)
//	{
//		cout << *iter << endl;
//	}
//}

