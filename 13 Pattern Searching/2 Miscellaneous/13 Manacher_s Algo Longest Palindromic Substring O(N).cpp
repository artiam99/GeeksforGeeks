#include<bits/stdc++.h>
using namespace std;
string LPS(string &s,int n)
{
    if(!n)  return s;
    
    string str;
	
	str += '$';
    
    for(int i = 0 ; i < n ; i++)
    str += '#' , str += s[i];
    
    str += '#' ;
	
	str += '@';
    
    int len = str.length();
    
    int P[len];

    int C = 1 , R = 1 , mx = 0 , mxi;

    for(int i = 1 ; i < len-1 ; i++)
    {
    	P[i] = 0;
    	
        int mirr = 2 * C - i;

        if(i < R)
        P[i] = min(R-i , P[mirr]);

        while(str[i + (P[i] + 1)] == str[i - (P[i] + 1)])
        P[i]++;

        if(i + P[i] > R)
        {
            C = i;

            R = i + P[i];
        }

        if(mx < P[i])
        {
            mx = P[i];
            
            mxi = i;
        }
    }
    
    return s.substr(((mxi-1)/2)-mx/2,mx);
}
signed main()
{
	string s = "ABABAB";
	int n = s.length();

	cout<< LPS(s,n);
	
	return 0;
}
