#include<bits/stdc++.h>
using namespace std;
int NCK(int n,int k)
{
	int res=1;
	
	if(n-k<k)
	k=n-k;
	
	for(int i=0;i<k;i++)
	{
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
signed main()
{
    int n=5,k=2;
    
    cout<< NCK(n,k) <<endl;
    
	return 0;
}
