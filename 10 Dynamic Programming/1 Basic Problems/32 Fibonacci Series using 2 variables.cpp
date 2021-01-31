#include<bits/stdc++.h>
using namespace std;
int Fibo(int n)
{
	int x=0,y=1;
	
	cout<<x<<" "<<y<<" ";
	
	for(int i=0;i<n-1;i++)
	{
		cout<<x+y<<" ";
		
		if(i&1)
		y=x+y;
		
		else
		x=y+x;
	}
	cout<<endl;
}
signed main()
{
	int n=9;
	
	Fibo(n);
	    
	return 0;
}
