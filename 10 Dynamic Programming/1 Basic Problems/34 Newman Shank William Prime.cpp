#include<bits/stdc++.h>
using namespace std;
int NSWP(int n)
{
	if(!n)
	return 1;
	
	int x=1,y=1;
	
	n--;
	while(n--)
	{
		if(n&1)
		x=2*y+x;
		else
		y=2*x+y;
	}
	return (x>=y)?x:y;
}
signed main()
{
	int n=3;
	
	cout<< NSWP(n); // S(N) = 2*S(N-1) + S(N-2) , S(0) = 1 , S(1) =1
	    
	return 0;
}
