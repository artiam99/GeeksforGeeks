#include<bits/stdc++.h>
using namespace std;
int CountBinaryStrings(int N)
{
	int z = 1 , o = 1;// for each iteration z and o are the values of Strings that end with 0 and 1 respectively
	
	int mod = 1000000007;
	
	for(int i=1;i<N;i++)
    {
        z = ( z % mod + o % mod ) % mod;
        o = ( mod + (z - o) %mod) % mod;
    }
    return ( z % mod + o % mod) % mod;
}
signed main()
{
	int N = 5;  //  For these type of questions we need differecnt variable or array to store values for different cases like z and o here .. same , diff in Fence Pairting Problem
	
	cout<< CountBinaryStrings(N) <<endl;
    
	return 0;
}
