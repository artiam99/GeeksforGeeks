#include<bits/stdc++.h>
using namespace std;

void Prime_Factors(int N)
{	
	for(int i = 2 ; i * i <= N ; i++)
	{
		while(N % i == 0)
		{
			cout << i << " ";
			
			N /= i;
		}
	}
	
	if(N >= 2)
	cout << N;
	
	cout << endl;
}

signed main()
{
	int N = 112;
	
	Prime_Factors(N);	
}
