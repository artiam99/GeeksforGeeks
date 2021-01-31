#include <bits/stdc++.h>
using namespace std;
void Min_Space(int W,int N,int M)
{
	int mn = INT_MAX;
	
	int n , m , i = 0;
	
	while(i*N <= W)
	{
		if(mn >= (W-i*N) - (floor((W-i*N)/M))*M)
		{
			mn = (W-i*N) - floor((W-i*N)/M)*M;
			
			n = i;
			
			m = floor((W-i*N)/M);
		}
		i++;
	}
	cout<< n << " " << m << " " << mn << endl;
}
int main()
{
	int W = 24 , N = 5 , M = 3;
	
	Min_Space(W,N,M);
	
	return 0;
}
