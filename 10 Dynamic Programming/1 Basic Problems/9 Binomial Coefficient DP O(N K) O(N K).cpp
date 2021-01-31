#include<bits/stdc++.h>
using namespace std;
int NCK(int n,int k)
{
	int C[n+1][k+1];// Making Pascal's triangle
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(j==0 || j==i)
			C[i][j]=1;
			
			else
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
	return C[n][k];
}
signed main()
{
    int n=5,k=2;
    
    cout<< NCK(n,k) <<endl;
    
	return 0;
}
