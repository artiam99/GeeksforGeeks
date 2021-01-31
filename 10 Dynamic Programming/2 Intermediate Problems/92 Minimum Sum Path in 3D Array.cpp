#include<bits/stdc++.h>
using namespace std;
int MinSumPath(vector<vector<vector<int>>> &a,int m,int n,int o)
{
	for(int i = 0 ; i < m ; i++)
	for(int j = 0 ; j < n ; j++)
	for(int k = 0 ; k < o ; k++)
	if(!(i==0 && j==0 && k==0))
	a[i][j][k] += min( ((i > 0) ? a[i-1][j][k] : INT_MAX) , min( ((j > 0) ? a[i][j-1][k] : INT_MAX) , ((k > 0) ? a[i][j][k-1] : INT_MAX) ) );
	
	return a[m-1][n-1][o-1];
}
signed main()
{
	vector<vector<vector<int>>> a = { { {1, 2} , {4, 3}},
    							      { {3, 4} , {2, 1}} };
    int m = a.size();
    int n = a[0].size();
    int o = a[0][0].size();
    
    cout<< MinSumPath(a,n,m,o) <<endl;
	
	return 0;
}
