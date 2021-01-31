#include<bits/stdc++.h>
using namespace std;
int mod = 1003;
struct cell
{
    int o,z;
    cell(int x,int y)
    {
        o = x;
        z = y;
    }
};
cell Rec(string &s,int l,int r,vector<vector<cell>> &dp)
{
    if(l == r)
    {
        if(s[l] == 'T')
        return cell(1,0);
        
        return cell(0,1);
    }
    if(dp[l][r].o != -1 && dp[l][r].z != -1)  return dp[l][r];
    
    cell ans(0,0);
    
    for(int i = l+1 ; i <= r-1; i+=2)
    {
        cell c1(0,0); c1 = Rec(s,l,i-1,dp);
        cell c2(0,0); c2 = Rec(s,i+1,r,dp);
        
        if(s[i] == '|')
        {
            ans.o = (ans.o % mod + (c1.o % mod * c2.o % mod) % mod + (c1.o % mod * c2.z % mod) % mod +
                     (c1.z % mod * c2.o % mod) % mod) % mod;
            
            ans.z = (ans.z % mod + (c1.z % mod * c2.z % mod) % mod) % mod;
        }
        else if(s[i] == '&')
        {
            ans.o = (ans.o % mod + (c1.o % mod * c2.o % mod) % mod) % mod ;
            
            ans.z = (ans.z %mod + (c1.o % mod * c2.z % mod) % mod + (c1.z % mod * c2.o % mod) % mod +
                     (c1.z % mod * c2.z % mod) % mod) %mod;
        }
        else
        {
            ans.o = (ans.o % mod +  (c1.o % mod * c2.z % mod) % mod + (c1.z % mod * c2.o % mod) %mod) % mod;
            
            ans.z = (ans.z %mod + (c1.o % mod * c2.o % mod) % mod + (c1.z % mod * c2.z % mod) % mod) % mod;
        }
    }
    return dp[l][r] = ans;
}
int BooleanParenthesization(string &s,int n)
{
	vector<vector<cell>> dp(n,vector<cell>(n,cell(-1,-1)));
	    
	return Rec(s,0,n-1,dp).o;
}
signed main()
{
	string s = "T|T&F^T";
	int n = s.length();
	
	cout<< BooleanParenthesization(s,n) <<endl;
    
	return 0;
}
