#include<bits/stdc++.h>
using namespace std;
int NPK(int n,int k)
{
	int P[n+1][k+1]; // P(N,K) = P(N-1,K) + K * P(N-1,K-1)  ,  P(N,0) = 1
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(j==0)
			P[i][j]=1;
			
			else
			P[i][j] = P[i-1][j] + j * P[i-1][j-1];
		}
	}
	
	return P[n][k];
}
signed main()
{
    int n=10,k=2;
    
    cout<< NPK(n,k) <<endl;
    
	return 0;
}
