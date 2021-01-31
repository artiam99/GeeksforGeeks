#include<bits/stdc++.h>
using namespace std;
bool isword(string s,vector<string> &a)
{
    for(auto i:a)
    if(i.compare(s) == 0)
    return true;
    
    return false;
}
bool wordBreak(string s,vector<string> &a)
{
	if(!s.length()) return true;
	
	bool dp[s.length()];  memset(dp,0,sizeof(dp));
	    
    for(int i=s.length()-1 ; i >=0 ; i--)
    for(int j=i ; j < s.length() ; j++)
    if(isword(s.substr(i,j-i+1),a) && (j==(s.length()-1) || dp[j+1]))
    {
        dp[i] = true;
        break;
    }
    
	return dp[0];
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
