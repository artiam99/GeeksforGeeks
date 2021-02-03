#include<bits/stdc++.h>
using namespace std;

int Kth_Smallest(vector<vector<int>> &a , int n , int k)
{
	if(k > n*n)  return -1;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    
    pq.push({a[0][0] , {0 , 0}});
    
    set<pair<int,int>> st;
    
    st.insert({0 , 0});
    
    for(int i = 0 ; i < k-1 ; i++)
    {
        int x = pq.top().second.first , y = pq.top().second.second;
        
        pq.pop();
        
        if(x < n-1 && st.find({x+1 , y}) == st.end())
        {
            st.insert({x+1 , y});
            
            pq.push({a[x+1][y] , {x+1 , y}});
        }
        
        if(y < n-1 && st.find({x , y+1}) == st.end())
        {
            st.insert({x , y+1});
            
            pq.push({a[x][y+1] , {x , y+1}});
        }
    }
    
    return pq.top().first;
}

signed main()
{
	vector<vector<int>> a =  { {16, 28, 60, 64},
			                   {22, 41, 63, 91},
			                   {27, 50, 87, 93},
			                   {36, 78, 87, 94 } };
	int n = a.size();
	int k = 3;
	
	cout << Kth_Smallest(a , n , k) << endl;
	
	return 0;
}
