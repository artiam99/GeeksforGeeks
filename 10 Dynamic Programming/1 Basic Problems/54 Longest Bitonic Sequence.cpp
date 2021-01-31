#include<bits/stdc++.h>
using namespace std;
int LBS(vector<int> &a,int n)
{
	vector<int> dpl(n,1),dpr(n,1);
	    
    for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
    {
        if(a[j]<a[i])
        dpl[i]=max(dpl[i],dpl[j]+1);
        
        if(a[n-j-1]<a[n-i-1])
        dpr[n-i-1]=max(dpr[n-i-1],dpr[n-j-1]+1);
    }
    
    int mx=dpl[0]+dpr[0]-1;
 
    for(int i=1;i<n;i++)
    mx=max(mx,dpl[i]+dpr[i]-1);
    
    return mx;
}
signed main()
{
	vector<int> a = {1, 11, 2, 10, 4, 5, 2, 1};
	int n = a.size();
    
    cout<< LBS(a,n) <<endl;
    
	return 0;
}
