#include<bits/stdc++.h>
using namespace std;
int Rec(int N,int S9[])
{
    if(N < 10)  return N * ( N + 1 ) / 2;
    
    int d = ceil(log10(N+1));
    
    int x = ( N / (int) pow(10 , d - 1) );
    
    int y = ( x * pow(10 , d - 1) - 1 );
    
    return ( S9[d-1] * x +   (x * (x - 1) / 2) * pow(10 , d - 1) ) + Rec(N - y - 1 , S9) + x * (N - y) ;
}
int SumofDigits(int N)
{
	if(N < 10)  return N * ( N + 1 ) / 2;
    
    int S9[7]; // S9[1] means ..Rec(9) , S9[2] .. Rec(99) and so on
    
    S9[1] = 45;
    
    for(int i = 2 ; i < 7 ; i++)
    S9[i] = S9[i-1] * 10 + 45 * pow(10 , i-1);
    
    return Rec(N,S9);
}
signed main()
{
	int N = 328;
	
	cout<< SumofDigits(N) <<endl;
	
	return 0;
}
