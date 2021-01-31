#include<bits/stdc++.h> 
using namespace std;
long long Smallest2sPower(long long n)
{
	if(!(n & (n-1)))  return n;
        
    n |= (n >> 1);
    
    n |= (n >> 2);
    
    n |= (n >> 4);
    
    n |= (n >> 8);
    
    n |= (n >> 16);
    
    n |= (n >> 32);
    
    return n + 1;
}
int main() 
{ 
	long long n = 5;
	
	cout << Smallest2sPower(n) << endl;
	
	return 0; 
} 

