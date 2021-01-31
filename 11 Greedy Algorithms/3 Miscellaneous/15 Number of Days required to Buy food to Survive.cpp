#include<bits/stdc++.h>
using namespace std;
void Survive(int S,int N,int M)
{
	if((S-(S/7)) * N < M * S)
	cout<< "No " <<endl;
	
	else
	cout<< "Yes " << ceil(M*S / (double)N) << endl;
}
signed main()
{
	int S = 10 , N = 16 , M = 2;
	
	Survive(S,N,M);
	
    return 0;
}
