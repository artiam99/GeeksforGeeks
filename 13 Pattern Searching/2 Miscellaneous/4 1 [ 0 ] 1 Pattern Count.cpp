#include<bits/stdc++.h>
using namespace std;
int PatternCount(string &s,int n)
{
	int cnt = 0;
            
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '1' && i+1 < n && s[i+1] == '0')
        {
            while(i+1 < n && s[i+1] == '0')
            i++;
            
            if(i+1 < n && s[i+1] == '1')
            cnt++;
        }
    }
    
    return cnt;
}
signed main()
{
	string s = "10001abc101";
	int n = s.length();
	
	cout<< PatternCount(s,n) << endl;;
	
	return 0;
}
