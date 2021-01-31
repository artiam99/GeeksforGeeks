#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

struct point
{
    int x , y;
    
    point(int x = 0 , int y = 0)
    {
    	this->x = x;
    	
    	this->y = y;
	}
};

int Orientation(point p , point q , point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);  //  p ----- q ----- r   slope of pq , m1 = (qy - py) / (qx - px) , slope of qr , m2 = (ry - qy) / (rx - qx)
    
    if(val == 0)  return 0;  // Co-linear
    
    return ((val > 0) ? 1 : 2);  // m1 > m2 pqr Clockwise , m1 < m2 Anti-clockwise , So (qy - py) * (rx - qx) - (qx - px) * (ry - qy)  Positive - Clockwise , Negative - Anti-clockwise
}

bool Is_Point_On_Segment(point p , point q , point r)
{
    return ((r.x <= max(p.x , q.x) && r.x >= min(p.x , q.x)) &&
            (r.y <= max(p.y , q.y) && r.y >= min(p.y , q.y)));
}

bool Is_Intersect(point p1 , point q1 , point p2 , point q2)
{
    int o1 = Orientation(p1 , q1 , p2);
    
    int o2 = Orientation(p1 , q1 , q2);
    
    int o3 = Orientation(p2 , q2 , p1);
    
    int o4 = Orientation(p2 , q2 , q1);
    
    if(o1 != o2 && o3 != o4)
    return true;
    
    if(o1 == 0 && Is_Point_On_Segment(p1 , q1 , p2))
    return true;
    
    if(o2 == 0 && Is_Point_On_Segment(p1 , q1 , q2))
    return true;
    
    if(o3 == 0 && Is_Point_On_Segment(p2 , q2 , p1))
    return true;
    
    if(o4 == 0 && Is_Point_On_Segment(p2 , q2 , q1))
    return true;
    
    return false;
}

signed main()
{
	point p1(10 , 0) , q1(0 , 10) , p2(0 , 0) , q2(10 , 10);
	
    if(Is_Intersect(p1 , q1 , p2 , q2))
    cout << "Intersect" << endl;
    
    else
    cout << "Not Intersect" << endl;
	
	return 0;
}

