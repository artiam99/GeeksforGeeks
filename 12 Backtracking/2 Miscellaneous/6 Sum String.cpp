#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
long long sttoi(string s)
{
    long long a = 0;
    
    for(int i = 0 ; i < s.length() ; i++)
    a = a*10 + s[i]-48;
    
    return a;
}
bool Rec(string &s,int k,int j,int i,int n)
{
    if(k == 0)  return true;

    long long c = sttoi(s.substr(j,i-j));
    
    long long b = sttoi(s.substr(k,j-k));

    for(int l = k-1 ; l >= 0 ; l--)
    {
        long long a = sttoi(s.substr(l,k-l));

        int d3 = ceil(log10(a+1));
        d3 = ((d3) ? d3 : 1);
        
        if(d3 != k-l)  continue;

        if(a > c)  return false;

        if(a+b == c && (l == 0 || Rec(s,l,k,j,i)))
        return true;
    }
    return false;
}
bool isSumString(string &s,int n)
{
    for(int i = n-1 ; i >= 2 ; i--)
    {
        long long c = sttoi(s.substr(i,n-i));
       
	    int d1 = ceil(log10(c+1));
        d1 = ((d1) ? d1 : 1);

        if(d1 != n-i)  continue;

        for(int j = i-1; j >= 1 ; j--)
        {
            long long b = sttoi(s.substr(j,i-j));
            
			int d2 = ceil(log10(b+1));
            d2 = ((d2) ? d2 : 1);
            
			if(d2 != i-j)  continue;

            if(b > c)  break;

            for(int k = j-1; k >= 0 ; k--)
            {
                long long a = sttoi(s.substr(k,j-k));
                
				int d3 = ceil(log10(a+1));
                
				d3 = ((d3) ? d3 : 1);
                
				if(d3 != j-k)  continue;

                if(a > c)  break;

                if(a + b == c && Rec(s,k,j,i,n))
                return true;
            }
        }
    }
    return false;
}
signed main()
{
	string s = "12243660";
	int n = s.length();
	    
	cout<< isSumString(s,n) << endl;

	return 0;
}
