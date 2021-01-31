#include<bits/stdc++.h>
using namespace std;
int MinSumSubMat(vector<vector<int>> &a,int n,int m)
{
	for(int i = 0 ; i < n ; i++)
	for(int j = 1 ; j < m ; j++)
	a[i][j] += a[i][j-1];
	
	int ans = INT_MAX;
    
    for(int i = 0 ; i < m ; i++)
    for(int j = i ; j < m ; j++)
    {
        int curr = a[0][j] - ((i > 0) ? a[0][i-1] : 0);
        
        int sofar = a[0][j] - ((i > 0) ? a[0][i-1] : 0);
        
        for(int k = 1 ; k < n ; k++)
        {
            curr = min(curr + a[k][j] - ((i > 0) ? a[k][i-1] : 0) , a[k][j] - ((i > 0) ? a[k][i-1] : 0));
            
            sofar = min(curr,sofar);
        }
        ans = min(ans ,sofar);
    }
    return ans;
}
signed main()
{
	vector<vector<int>> a = { {   1 ,   2 ,  -1 ,  -4 , -20 },
                 			  {  -8 ,  -3 ,   4 ,   2 ,   1 },
                			  {   3 ,   8 ,  10 ,   1 ,   3 },
                			  {  -4 ,  -1 ,   1 ,   7 ,  -6 } };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MinSumSubMat(a,n,m) <<endl;
	
	return 0;
}
