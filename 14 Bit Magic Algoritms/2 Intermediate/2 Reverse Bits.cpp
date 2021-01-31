#include<bits/stdc++.h> 
using namespace std;
long long ReverseBits(long long n)
{
	for(int i = 32 ; i > 16 ; i--)
    {
        long long l = ((((1 << (i-1)) & n) >> (i-1)) << (32 - i));
        
        long long r = ((((1 << (32 - i)) & n) >> (32 - i)) << (i-1));
        
        n &= ~(1 << (i-1));
        n &= ~(1 << (32 - i));
        
        n |= l;
        n |= r;
    }
    return n;
}
int main() 
{ 
	long long n = 1;
	
	cout << ReverseBits(n) << endl;
	
	return 0; 
} 

