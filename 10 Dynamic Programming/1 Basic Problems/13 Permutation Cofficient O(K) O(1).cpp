#include<bits/stdc++.h>
using namespace std;
int NPK(int n,int k)
{
	int res=1;
	
	for(int i=0;i<k;i++)
	res*=(n-i);
	
	return res;
}
signed main()
{
    int n=10,k=2;
    
    cout<< NPK(n,k) <<endl;
    
	return 0;
}
