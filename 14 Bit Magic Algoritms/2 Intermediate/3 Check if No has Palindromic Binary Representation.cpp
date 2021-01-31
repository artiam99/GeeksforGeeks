#include<bits/stdc++.h> 
using namespace std;
bool isPal(long long n)
{
	long long l = n;
        
    l |= (l >> 1); l |= (l >> 2); l |= (l >> 4); l |= (l >> 8); l |= (l >> 16); l |= (l >> 32); l++; l >>= 1;
    
    long long r = 1;
    
    while(l > r)
    {
        if(((bool)(l & n)) ^ ((bool)(r & n)))
        return false;
        
        l >>= 1;
        
        r <<= 1;
    }
    return true;
}
int main() 
{ 
	long long n = 17;
	
	if(isPal(n))  cout << "YES" << endl;
	
	else cout << "NO" << endl;
	
	return 0; 
} 

