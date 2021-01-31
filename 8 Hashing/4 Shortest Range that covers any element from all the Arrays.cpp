#include <bits/stdc++.h>
using namespace std;

pair<int,int> Shortest_Range(vector<vector<int>> &a , int n , int k)  // Reduce Complexity by implementing a heap
{
    int ind[k];
    
    for(int i = 0 ; i < k ; i++)
    ind[i] = 0;
     
    int mn = INT_MAX;
    pair<int,int> ans;
    
    while(1)
    {
        int l = INT_MAX , li , r = INT_MIN;
        
        for(int i = 0 ; i < k ; i++)
        {
            if(l > a[i][ind[i]])
            {
                l = a[i][ind[i]];
                
                li = i;
            }
            
            r = max(r , a[i][ind[i]]);
        }
        
        if(r - l < mn)
        {
            mn = r - l;
            
            ans = {l , r};
        }
        
        ind[li]++;
        
        if(ind[li] == n)
        break;
    }
    
    return ans;
}

int main()
{
	vector<vector<int>> a = { {1, 3, 5, 7, 9},
                              {0, 2, 4, 6, 8},
                              {2, 3, 5, 7, 11} };
	int k = a.size();
	int n = a[0].size();
	
	pair<int,int> ans = Shortest_Range(a , n , k);
	
	cout << ans.first << " " << ans.second << endl;
	
	return 0;
}
