#include<bits/stdc++.h>
using namespace std;
int NoofWays(int x,int y)
{
	int n = x+y , k = min(x,y);
	
	int C[k+1];
	memset(C,0,sizeof(C));
	C[0]=1;
	
	for(int i=0;i<n;i++)
	for(int j=min(i,k)+1;j>0;j--)
	C[j]+=C[j-1];
	
	return C[k];
}
signed main()
{
	int x = 3 , y = 6; // Move down or left
	
	cout<< NoofWays(x,y) <<endl;
	
	return 0;
}
