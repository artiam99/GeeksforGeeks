#include<bits/stdc++.h>
using namespace std;
void Rec(string &s,int n,int k,string &ans,int i)
{
    if(i == n || k == 0)
    {
        if(ans < s)
        ans = s;
        
        return;
    }
    
    Rec(s,n,k,ans,i+1);
    
    for(int j = i + 1 ; j < n ; j++)
    if(s[i] < s[j])
    {
        swap(s[i],s[j]);
        Rec(s,n,k-1,ans,i+1);
        swap(s[i],s[j]);
    }
}
string findMaximumNum(string s, int n, int k)
{   
    string ans = s;
   
    Rec(s,n,k,ans,0);
    
    return ans;
}
signed main()
{
	string s = "1234567";
	int n = s.length();
	int k = 4;
	
	cout<< findMaximumNum(s,n,k) << endl;
	
	return 0;
}
