#include<bits/stdc++.h>
using namespace std;
#define int long long
bool DFS(int x,int y,vector<vector<int>> &a,int n,vector<vector<bool>> &ans)
{
    ans[x][y] = 1;
    
    if(x == n-1 && y == n-1)  return true;
    
    if(a[x][y] == 0)
    {
        ans[x][y] = 0;
        
        return false;
    }

    for(int i = 1 ; i <= a[x][y] ; i++)
    {
        if(y + i < n && DFS(x,y+i,a,n,ans))
        return true;
        
        if(x + i < n && DFS(x+i,y,a,n,ans))
        return true;
    }
    
    ans[x][y] = 0;
    
    return false;
}
void Rat(vector<vector<int>> &a,int n)
{
	vector<vector<bool>> ans(n,vector<bool>(n));
	    
    if(!DFS(0,0,a,n,ans))
    cout<< -1 << endl;
    
    else
    {
        for(auto i : ans)
        {
            for(auto j : i)
            cout<< j << " ";
            cout<< endl;
        }
    }
}
signed main()
{
	vector<vector<int>> a = { {2, 1, 0, 0},
							  {3, 0, 0, 1},
							  {0, 1, 0, 1},
							  {0, 0, 0, 1} };
	int n = a.size();
	
	Rat(a,n);
	
	return 0;
}
