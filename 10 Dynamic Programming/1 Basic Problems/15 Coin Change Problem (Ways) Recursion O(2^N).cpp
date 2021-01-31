#include<bits/stdc++.h>
using namespace std;
int CountWay(vector<int> &a,int m,int n)
{
	if(n==0)
	return 1;
	
	if(n<0)
	return 0;
	
	if(m<=0 && n>=1)
	return 0;
	
	return CountWay(a,m-1,n) + CountWay(a,m,n-a[m-1]);
}
signed main()
{
    vector<int> a={1,2,3};
    int m=a.size();
    
    int n=4;
    
    cout<< CountWay(a,m,n) <<endl;
    
	return 0;
}
