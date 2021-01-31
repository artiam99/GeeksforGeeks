#include<bits/stdc++.h>
using namespace std;
float SubsetAvg(vector<int> &a,int n)
{
	int sum = accumulate(a.begin(),a.end(),0);    
	
    int C[n];  memset(C,0,sizeof(C));  C[0] = 1;
    
    for(int i = 1 ; i < n ; i++)
    for(int j = i ; j > 0 ; j--)
    C[j] += C[j-1];
    
    double ans = 0;
    
    for(int i=1;i<=n;i++)
    ans += (C[i-1] / (double)i);
    
    return ans * sum;
}
signed main()
{
	vector<int> a = {2, 3, 5, 7};
	int n = a.size();
	
	cout<< SubsetAvg(a,n) <<endl;
	
	return 0;
}
