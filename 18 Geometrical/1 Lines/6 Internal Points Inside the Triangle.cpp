#include<bits/stdc++.h>
using namespace std;

/*
	Pick's Theeorem :  A = I + (B / 2) -1
	
	A ==> Area of Polygon
	B ==> Number of integral points on edges of polygon
	I ==> Number of integral points inside the polygon
	
	See This : https://www.youtube.com/watch?v=bYW1zOMCQno
*/

class Point
{
	public :

    int x , y;
    
	Point(int a = 0 , int b = 0) : x(a) , y(b) {}
};

int Get_Boundary_Count(Point p , Point q)
{
    if (p.x == q.x)
    return abs(p.y - q.y) - 1;
    
	if (p.y == q.y)
    return abs(p.x - q.x) - 1;
 
    return __gcd(abs(p.x - q.x) , abs(p.y - q.y)) - 1;
}

int Get_Internal_Count(Point p , Point q , Point r)
{
    int BoundaryPoints = Get_Boundary_Count(p , q) + Get_Boundary_Count(p , r) + Get_Boundary_Count(q , r) + 3;
 
    int doubleArea = abs(p.x * (q.y - r.y) + q.x * (r.y - p.y) + r.x*(p.y - q.y));
 
    return (doubleArea - BoundaryPoints + 2) / 2;
}

signed main()
{
	Point p(0 , 0);
    Point q(5 , 0);
    Point r(0 , 5);
    
    cout << "Number of integral points inside given triangle is " << Get_Internal_Count(p , q , r) << endl;
	
	return 0;
}

