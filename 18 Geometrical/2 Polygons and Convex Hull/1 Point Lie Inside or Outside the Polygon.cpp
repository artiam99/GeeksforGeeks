#include<bits/stdc++.h>
using namespace std;

#define INF 10000

struct Point
{
	int x , y;
};

bool onSegment(Point p , Point q , Point r)
{
	return (q.x <= max(p.x , r.x) && q.x >= min(p.x , r.x) && q.y <= max(p.y , r.y) && q.y >= min(p.y , r.y));
}

int orientation(Point p , Point q , Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;
	
	return ((val > 0)? 1: 2);
}

bool doIntersect(Point p1 , Point q1 , Point p2 , Point q2)
{
	int o1 = orientation(p1 , q1 , p2);
	
	int o2 = orientation(p1 , q1 , q2);
	
	int o3 = orientation(p2 , q2 , p1);
	
	int o4 = orientation(p2 , q2 , q1);

	if (o1 != o2 && o3 != o4) return true;

	if (o1 == 0 && onSegment(p1 , p2 , q1)) return true;

	if (o2 == 0 && onSegment(p1 , q2 , q1)) return true;

	if (o3 == 0 && onSegment(p2 , p1 , q2)) return true;

	if (o4 == 0 && onSegment(p2 , q1 , q2)) return true;

	return false;
}

bool isInside(Point polygon[] , int n , Point p)
{
	if (n < 3)  return false;

	Point extreme = {INF , p.y};
	
	int count = 0 , i = 0;
	
	do
	{
		int next = (i + 1) % n;

		if(doIntersect(polygon[i] , polygon[next] , p , extreme))
		{
			if (orientation(polygon[i] , p , polygon[next]) == 0)
			return onSegment(polygon[i] , p , polygon[next]);

			count++;
		}
		
		i = next;
		
	}while (i != 0);

	return (count & 1);
}

signed main()
{
	Point polygon1[] = {{0 , 0} , {10 , 0} , {10 , 10} , {0 , 10}};
	int n = sizeof(polygon1) / sizeof(polygon1[0]);
	
	Point p = {20 , 20};
	isInside(polygon1, n, p)? cout << "Yes \n": cout << "No \n";

	p = {5 , 5};
	isInside(polygon1 , n , p) ? cout << "Yes \n": cout << "No \n";

	Point polygon2[] = {{0 , 0} , {5 , 5} , {5 , 0}};
	n = sizeof(polygon2) / sizeof(polygon2[0]);
	
	p = {3, 3};
	isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

	p = {5, 1};
	isInside(polygon2, n, p)? cout << "Yes \n": cout << "No \n";

	p = {8 , 1};
	isInside(polygon2 , n , p) ? cout << "Yes \n" : cout << "No \n";

	Point polygon3[] = {{0 , 0} , {10 , 0} , {10 , 10} , {0 , 10}};
	n = sizeof(polygon3) / sizeof(polygon3[0]);
	
	p = {-1 , 10};
	isInside(polygon3 , n , p) ? cout << "Yes \n" : cout << "No \n";

	return 0;
}

