#include<bits/stdc++.h> 
using namespace std;
int SwapBits(int x,int p1,int p2,int n)
{
	int p = (1 << n) - 1;
        
    int pp1 = (((x & (p << p1)) >> p1) << p2);
    
    int pp2 = (((x & (p << p2)) >> p2) << p1);
    
    x &= ~(p << p1);
    x &= ~(p << p2);
    
    x |= pp1;
    x |= pp2;
    
    return x;
}
int main() 
{ 
	int x = 28 , p1 = 0 , p2 = 3 , n = 2;
	
	cout << SwapBits(x,p1,p2,n) << endl;
	
	return 0; 
} 

