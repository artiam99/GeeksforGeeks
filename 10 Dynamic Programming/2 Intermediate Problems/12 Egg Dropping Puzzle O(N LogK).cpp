#include<bits/stdc++.h>
using namespace std;
int BinomialCoeffSum(int n,int k)
{
	int sum = 0 , p = 1;
	
	for(int i=0;i<k;i++)
	{
		p *= (n-i);
		p /= (i+1);
		
		sum += p;
	}
	return sum;
}
int MinimumTrial(int n,int k)
{
	int low = 1;
	int high = k;
	
	while(low < high)
	{
		int mid = low + (high-low)/2;
		
		if( BinomialCoeffSum(mid,n) < k )
		low = mid + 1;
		
		else
		high = mid;
	}
	return low;
}
signed main()
{
	int Egg = 2 , Floor = 100;
	
	cout<< MinimumTrial(Egg,Floor) <<endl;
    
	return 0;
}

