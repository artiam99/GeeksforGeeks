#include<bits/stdc++.h>
using namespace std;
int No_of_ways(int n,int k)
{
	if(k==2)
	return n-1;
	return pow(n-1,k-1) - No_of_ways(n,k-1);
}
signed main()
{
    int n=4,k=2;
    
    cout<<No_of_ways(n,k);
	
	return 0;
}
