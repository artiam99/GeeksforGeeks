#include<bits/stdc++.h>
using namespace std;
int MaximumGold(vector<vector<int>> &a,int n,int m)
{
	for(int j=1;j<m;j++)
	for(int i=0;i<n;i++)
	a[i][j]+=max(a[i][j-1] , max(((i!=0) ? a[i-1][j-1] : 0),((i!=n-1) ? a[i+1][j-1]:0)));
	
	int mx=0;
	for(int i=0;i<n;i++)
	mx=max(mx,a[i][m-1]);
	
	return mx;
}
signed main()
{
    vector<vector<int>> a={{1, 3, 3},
                		   {2, 1, 4},
                		   {0, 6, 4}};
    int n=a.size();
    int m=a[0].size();
    
    cout<< MaximumGold(a,n,m) <<endl;
    
	return 0;
}
