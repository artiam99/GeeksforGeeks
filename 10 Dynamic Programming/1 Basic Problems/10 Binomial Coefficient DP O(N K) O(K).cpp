#include<bits/stdc++.h>
using namespace std;
int NCK(int n,int k)
{
	int C[k+1];// Making Pascal's triangle row in wach iteration
	C[0]=1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i,k);j>0;j--)
		C[j] = C[j] + C[j-1];
	}
	return C[k];
}
signed main()
{
    int n=5,k=2;
    
    cout<< NCK(n,k) <<endl;
    
	return 0;
}
