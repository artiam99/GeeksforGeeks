#include<bits/stdc++.h>
using namespace std;
bool isword(string s,vector<string> &a)
{
    for(auto i:a)
    if(i.compare(s) == 0)
    return true;
    
    return false;
}
bool WordBreakUnitll(string &s,int l,int r,vector<string> &a,vector<int> &dp)
{
    if(dp[l] != -1)  return dp[l];
    
    for(int i=l ; i <= r ; i++)
    if(isword(s.substr(l,i-l+1),a) && (i==r || WordBreakUnitll(s,i+1,r,a,dp)))
    return dp[l] = true;
    
    return dp[l] = false;
}
bool wordBreak(string s,vector<string> &a)
{
	if(!s.length()) return true;
	
	vector<int> dp(s.length(),-1);
	    
	return WordBreakUnitll(s,0,s.length()-1,a,dp) ;
}
signed main()
{
	vector<string> a = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};	
	
	wordBreak("ilikesamsung", a)? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii", a)? cout <<"Yes\n": cout << "No\n";
    wordBreak("", a)? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii", a)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango", a)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok", a)? cout <<"Yes\n": cout << "No\n";
    
	return 0;
}
