#include<bits/stdc++.h>
using namespace std;
int Number_of_Sub_Matrix(vector<vector<int>> &a,int n,int m)
{
	for(int i = 0 ; i < n ; i++)
	for(int j = 1 ; j < m ; j++)
	a[i][j] += a[i][j-1];
	
	int cnt = 0;
	
	for(int i = 0 ; i < m ; i++)
	for(int j = i ; j < m ; j++)
	{
		map<int,int> mp;
		
		mp[0] = 1;
		
		int curr = 0;
		
		for(int k = 0 ; k < n ; k++)
		{
			curr += a[k][j] - ((i==0) ? 0 : a[k][i-1]);
			
			cnt += mp[curr];
			
			mp[curr]++;
		}
	}
	return cnt;
}
signed main()
{
	vector<vector<int>> a = { { 9,  7, 16, 5 },
							  { 1, -6, -7, 3 }, 
                              { 1,  8,  7, 9 },
							  { 7, -2,  0, 10} }; 
    int n = a.size();
    int m = a[0].size();
    
    cout<< Number_of_Sub_Matrix(a,n,m) <<endl;
    
	return 0;
}
