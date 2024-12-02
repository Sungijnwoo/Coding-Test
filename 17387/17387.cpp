#include <iostream>
#include <math.h>
using namespace std;

struct Point {
	double x, y;
};

bool intersect(Point A, Point B, Point C, Point D) {
	double denom = (B.x - A.x) * (D.y - C.y) - (B.y - A.y) * (D.x - C.x);
	if (abs(denom)==0)
		// 평행한 경우
	{
		double check = (C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x);
		if (abs(check) ==0)
		{
			if (((A.x < C.x && B.x < C.x && A.x < D.x && B.x < D.x)|| (A.y < C.y && B.y < C.y && A.y < D.y && B.y < D.y))
				|| ((A.x > C.x && B.x > C.x && A.x > D.x && B.x > D.x) || (A.y > C.y && B.y > C.y && A.y > D.y && B.y > D.y)))
				return 0;
			else
				return 1;
		}
		else
			return 0;
	}

	double t = ((C.x - A.x) * (D.y - C.y) - (C.y - A.y) * (D.x - C.x)) / denom;
	double s = ((C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x)) / denom;

	return (0 <= t && t <= 1) && (0 <= s && s <= 1);
}

int main()
{
	double x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	
	Point A = { x1,y1 };
	Point B = { x2,y2 };
	Point C = { x3, y3 };
	Point D = { x4, y4 };

	cout << intersect(A, B, C, D);

	

	
}