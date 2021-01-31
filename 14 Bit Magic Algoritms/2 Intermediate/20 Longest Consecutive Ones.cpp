#include<bits/stdc++.h> 
using namespace std;
int LCO(int x)
{
	int mx = 0 , curr = 0;
    
    while(x)
    {
        if(x & 1)  curr++;
        
        else curr = 0;
        
        mx = max(mx , curr);
        
        x >>= 1;
    }
    
    return mx;
}
int main() 
{ 
	int x = 14;
	
	cout << LCO(x) << endl;
	
	return 0; 
} 

