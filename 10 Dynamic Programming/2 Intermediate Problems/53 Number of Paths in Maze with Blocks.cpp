#include<bits/stdc++.h>
using namespace std;
int countPaths(vector<vector<int>> &a,int n,int m)
{
	a[0][0] = 1;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(a[i][j]!=-1)
	a[i][j] += ( (i > 0 && a[i-1][j] != -1 ) ? a[i-1][j] : 0 ) + ( ( j > 0 && a[i][j-1] != -1 ) ? a[i][j-1] : 0 );
	
	return a[n-1][m-1];
}
signed main()
{
	vector<vector<int>> a =  {{0,  0, 0, 0},
                       		  {0, -1, 0, 0},
                       		  {-1, 0, 0, 0},
                      		  {0,  0, 0, 0}};
    int n = a.size();
    int m = a[0].size();
    
	cout << countPaths(a,n,m) <<endl;
    
	return 0;
}
