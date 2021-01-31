#include<bits/stdc++.h>
using namespace std;

int Distance(pair<int,int> &p , pair<int,int> &q , pair<int,int> &r)
{
    int x1 = p.first - q.first , y1 = p.second - q.second;

    int dist1 = (y1 * y1) + (x1 * x1);

    int x2 = p.first - r.first , y2 = p.second - r.second;

    int dist2 = (y2 * y2) + (x2 * x2);

    return dist1 - dist2;
}

int Orientation(pair<int,int> &p , pair<int,int> &q , pair<int,int> &r)
{
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second); 
  
    if(val == 0) return 0;
    
    return ((val > 0) ? 1 : 2);
}

void Convex_Hull(vector<pair<int,int>> &points , int n)
{
    set<pair<int,int>> result;
    
    pair<int,int> start;
    
	start = points[0];
    
	for(int i = 0 ; i < n ; i++)
    if(start.first > points[i].first)
    start = points[i];
    
    pair<int,int> curr = start;
    
	result.insert(start);

    while(true)
    {
        set<pair<int,int>> colinear; 
    
	    pair<int,int> next = points[0];
    
	    for(int i = 0 ; i < n ; i++)
        {
            if(points[i] == curr)
            continue;
            
            int val = Orientation(curr , next , points[i]);
           
		    if(val == 2)
            {
                next = points[i];
            
			    colinear.clear();
            }
            
            else if(val == 0)
            {
                int dist = Distance(curr , next , points[i]);
                
                if(dist < 0)
                {
                    colinear.insert(next);
   
                    next = points[i];
                }
            	
				else
                colinear.insert(points[i]);
            }
        }
 
        /* 
        	Considering Co-linear Points
        	
			for(auto i : colinear)
          	result.insert(i);
		*/
   
        if(next == start)
        break;
   
        result.insert(next);

        curr = next;
    }
    
    for(auto i : result)
    cout << i.first << " " << i.second << endl;
}

signed main()
{
	vector<pair<int,int>> points = {{0 , 3} , {2 , 2} , {1 , 1} , {2 , 1} , {3 , 0} , {0 , 0} , {3 , 3}};
    int n = points.size();
    
	Convex_Hull(points , n);
	
	return 0;
}

