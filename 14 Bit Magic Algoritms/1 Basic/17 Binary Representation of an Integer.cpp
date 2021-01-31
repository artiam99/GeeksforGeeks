#include<bits/stdc++.h>
using namespace std;
string Binary(int n)
{
	string s;
        
    while(n)
    {
        s += 48 + n % 2;
        
        n >>= 1;
    }
    
    for(int i = s.length() ; i < 32 ; i++)
    s += 48;
    
    reverse(s.begin(),s.end());
    
    return s;
}
signed main()
{
	int n = 18;
	
	cout<< Binary(n) << endl;
	
	return 0;
}
