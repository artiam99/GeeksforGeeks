#include<bits/stdc++.h>
using namespace std;
int Largest_Sub_Matrix(vector<vector<int>> &a,int n,int m,int k)
{
	for(int i = 0 ; i < n ; i++)
	for(int j = 1 ; j < n ; j++)
	a[i][j] += a[i][j-1];
	
	int mx = INT_MIN;
	
	for(int i = 0 ; i < m ; i++)
	for(int j = i ; j < m ; j++)
	{
		int in[k];
		
		for(int l = 1 ; l < k ; l++)
		in[i] = -2;
		
		in[0] = -1;
		
		int curr = 0;
		
		for(int l = 0 ; l < n ; l++)
		{
			curr += a[l][j] - ((i == 0) ? 0 : a[l][i-1]);
			
			if(curr >= 0)
			{
				if( in[(k - curr % k) % k] != -2 )
				mx = max(mx , (j-i+1) * (l - in[(k - curr % k) % k]));
				
				if(in[curr % k] == -2)
				in[curr % k] = l;
			}
		}
	}
	return mx;
}
signed main()
{
	vector<vector<int>> a = { { 1,  2, -1, -4},
                		      {-8, -3,  4,  2},
                  		      { 3,  8, 10,  1},
                    		  {-4, -1,  1,  7} };
    int n = a.size();
    int m = a[0].size();
    
    int k = 5;
    
    cout<< Largest_Sub_Matrix(a,n,m,k) <<endl;
    
	return 0;
}
