#include<bits/stdc++.h>
using namespace std;
int Paint(int n,int k)
{
	int total=k;
	
	int same=0,diff=k;
	
	for(int i=2;i<=n;i++)
	{
		same=diff;
		
		diff = (k-1)*total;
		
		total = same + diff;
	}
	
	return total;
}
signed main()
{
	int n=3,k=2;
	
	cout<< Paint(n,k);
	    
	return 0;
}
