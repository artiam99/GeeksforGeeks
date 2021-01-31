#include<bits/stdc++.h>
using namespace std;
int MaxOnes(vector<vector<bool>> &mat,int n,int m)
{
	int a[n][m+1];
	
	int cnt = 0;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j <= m ; j++)
	{
		if(j == 0) a[i][j] = 0;
		
		else
		{
			a[i][j] = a[i][j-1];
			
			if(mat[i][j-1] == 0)
			a[i][j] += 1;
			
			else
			{
				a[i][j] += -1;
				cnt++;
			}
		}
	}
	int mx = INT_MIN;
	
	for(int i = 1 ; i <=m ; i++)  // Maximum Square SubMatrix by Sliding Window
	for(int j = i ; j <=m ; j++)
	{
		int w = j-i+1;
		
		int curr = 0;
		
		for(int k = 0 ; k <= n ; k++)
		{
			if(k < w)
			curr += a[k][j] - a[k][i-1];

			else
			{
				mx = max(mx, curr);
				
				if(k==n)
				break;
				
				curr += a[k][j] - a[k][i-1] - ( a[k-w][j] - a[k-w][i-1] );
			}
		}
	}
	return mx + cnt;
}
signed main()
{
	vector<vector<bool>> mat = { { 0, 0, 1}, 
    						     { 0, 0, 1}, 
    						     { 1, 0, 1} } ;
    int n = mat.size();
    int m = mat[0].size();
    
    cout<< MaxOnes(mat,n,m) <<endl;
	
	return 0;
}
