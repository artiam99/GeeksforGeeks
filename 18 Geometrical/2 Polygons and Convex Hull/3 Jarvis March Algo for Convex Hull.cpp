#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Point
{
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int orientation(Point p, Point q, Point r)
{   
    int val = (((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y)));
    
    if(val == 0) return 0; // colinear
    if(val > 0) return 1; // clockwise
    return 2; // counter-clockwis 
}

double distance(Point p, Point q)
{
    return sqrt(((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y)));
}

vector<Point> convexHull(vector<Point> &points, int n)
{
    int start = 0;
        
    for(int i = 0; i < n; i++)
    if(points[i].x < points[start].x ||
       (points[i].x == points[start].x && points[i].y < points[start].y))
        start = i;
    
    
    // storing indices for convex hull points.
    vector<int> ansInd;
    ansInd.push_back(start);
    
    int p = start;
    
    // vis array to check if already visited or not.
    vector<bool> vis(n);
    vis[p] = true;
    
    do
    {   
        // choosing any point other than p. 
        int q = (p + 1) % n;
        
        
        for(int i = 0; i < n; i++)
        {   
            // if Counter clockwise orientation for p - i - q is found
            if(orientation(points[p], points[i], points[q]) == 2)
            {
                // Update q to i.   
                q = i;      
            }   
        }
        
        // if no counter-clockwise points are found then
        // it is guaranteed q was counter-clockwise most point 
        int farthestColinear = q;
        
        for(int i = 0; i < n; i++)
        {
            // if p - i - q are colinear
            if(i != p && orientation(points[p], points[i], points[q]) == 0)
            {
                if(!vis[i])
                {
                    vis[i] = true;
                    
                    // if you want to store colinear points store here and use vis array.
                    ansInd.push_back(i);

                    // remember they are not sorted wrt distance from p.
                    // if order is required sort them wrt distance form p.
                }
                
                // find farthes Colinear point with p - q from p.
                if(distance(points[p], points[farthestColinear]) < distance(points[p], points[i]))
                    farthestColinear = i;   
            }
        }
        
        
        // If you don't want to store colinear points store fathers colinear point here.
        //ansInd.push_back(farthestColinear);
        
        p = farthestColinear;
        
    } while(p != start);
    
    vector<Point> ans;
    
    for(int i = 0; i < ansInd.size(); i++)
        ans.push_back(points[ansInd[i]]);
    
    return ans;
}
signed main()
{        
    vector<Point> points = {{3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 4}, {1, 3}, {1, 2}, {2, 1}, {4, 2}, {0, 3}};
    int n = points.size();

    vector<Point> hull = convexHull(points, n);
        
    for(auto i: hull)
        cout << "(" << i.x << ", " << i.y << "), ";
    cout << endl;
}
