#include<bits/stdc++.h>
using namespace std;
int NCK(int n,int k)
{
	if(k==0 || k==n)
	return 1;
	
	return NCK(n-1,k) + NCK(n-1,k-1);
}
signed main()
{
    int n=5,k=2;
    
    cout<< NCK(n,k) <<endl;
    
	return 0;
}
