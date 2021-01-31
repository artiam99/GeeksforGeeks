#include<bits/stdc++.h>
using namespace std;
int CountWays(int n)
{
	vector<int> A(n+1); // Number of ways to make full Cube of size i is equal to A[i] 
	
	vector<int> B(n+1);// Number of ways to make one corner missing cube of size i is equal to B[i]
	
	A[0]=1; A[1]=0; B[0]=1; B[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		A[i] = A[i-2] + 2*B[i-1];
		B[i] = A[i-1] + B[i-2];
	}
	return A[n];
}
signed main()
{
	int n=8;// 3xn dominoe to be filled with 2x1 tile
	
	cout<< CountWays(n);
	    
	return 0;
}
