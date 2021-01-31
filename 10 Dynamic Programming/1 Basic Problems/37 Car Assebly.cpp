#include<bits/stdc++.h>
using namespace std;
int CarAssembly(vector<int> a[],vector<int> t[],int n,pair<int,int> e,pair<int,int> x)
{
	a[0][0]+=e.first;
	a[1][0]+=e.second;
	
	for(int i=1;i<n;i++)
	{
		a[0][i] += min(a[0][i-1] , a[1][i-1] + t[1][i]);
		a[1][i] += min(a[1][i-1] , a[0][i-1] + t[0][i]);
	}
	
	return min(a[0][n-1] + x.first , a[1][n-1] + x.second);
}
signed main()
{
	vector<int> a[2] = {{4, 5, 3, 2},
                        {2, 10, 1, 4}};
    
    vector<int> t[2] = {{0, 7, 4, 5},
                        {0, 9, 2, 8}};
    int n=a[0].size();
    
    pair<int,int> e = {10, 12};
	pair<int,int> x = {18, 7};
	
	cout<< CarAssembly(a,t,n,e,x) <<endl;
    
	return 0;
}
