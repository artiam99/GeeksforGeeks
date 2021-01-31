#include<bits/stdc++.h>
using namespace std;
int EndlessPoints(vector<vector<bool>> &a,int n,int m)
{
	int R[n][m] , C[n][m];
	
	for(int i=n-1;i>=0;i--)
	{
		int endless = 1;
		for(int j=m-1;j>=0;j--)
	    {
	    	if(a[i][j] == 0)
	    	endless = 0;
	    	
	    	R[i][j] = endless;
		}
	}
	
	for(int j=m-1;j>=0;j--)
	{
		int endless = 1;
		for(int i=n-1;i>=0;i--)
	    {
	    	if(a[i][j] == 0)
	    	endless = 0;
	    	
	    	C[i][j] = endless;
		}
	}
	
	int cnt = 0;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cnt += (R[i][j] & C[i][j]);
	
	return cnt;
}
signed main()
{
	vector<vector<bool>> a = { {1, 0, 1, 1}, 
                        	   {0, 1, 1, 1}, 
                        	   {1, 1, 1, 1}, 
                         	   {0, 1, 1, 0} }; 
    
	int n = a.size() , m = a[0].size();
	
	cout<< EndlessPoints(a,n,m) <<endl;
	
	return 0;
}
