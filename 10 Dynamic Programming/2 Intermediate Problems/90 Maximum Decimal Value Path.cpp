#include<bits/stdc++.h>
using namespace std;
int MaxDecPath(vector<vector<int>> &a,int n,int m)
{	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
	a[i][j] = a[i][j] * pow(2 , i + j) + max ( ( (i > 0) ? a[i-1][j] : 0) , ( (j > 0) ? a[i][j-1] : 0) );  // a[i][j] as a i + j distance for (0,0)
		
	return a[n-1][m-1];
}
signed main()
{
	vector<vector<int>> a = { {1, 1, 0, 1},
                			  {0, 1, 1, 0},
                			  {1, 0, 0, 1},
                			  {1, 0, 1, 1} };
    int n = a.size();
    int m = a[0].size();
    
    cout<< MaxDecPath(a,n,m) <<endl;
	
	return 0;
}
