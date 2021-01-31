#include<bits/stdc++.h>
using namespace std;
int MinCost(vector<vector<int>> &a,int n,int m)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		int x = min( ((i>0 && j>0) ? a[i-1][j-1] : INT_MAX) , min( ((i>0) ? a[i-1][j] : INT_MAX) , ((j>0) ? a[i][j-1] : INT_MAX) ) ) ;
		
		a[i][j] += ((x != INT_MAX) ? x : 0);
	}
	return a[n-1][m-1];
}
signed main()
{
	vector<vector<int>> a = { {1, 2, 3}, 
                    		  {4, 8, 2}, 
                    		  {1, 5, 3} };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MinCost(a,n,m) <<endl;
    
	return 0;
}
