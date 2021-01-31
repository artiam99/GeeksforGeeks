#include<bits/stdc++.h>
using namespace std;
void Rec(string &s,int n,int i,string &ans)
{
    if(i == n-1)
    {
        ans.push_back(s[i]);
        
        cout<<"("<<ans<<")";
        
		ans.pop_back();
        
		return;
    }
    ans.push_back(s[i]);
    
	ans.push_back(' ');
    
	Rec(s,n,i+1,ans);
    
	ans.pop_back();
    
	Rec(s,n,i+1,ans);
    
	ans.pop_back();
}
void SpacePermutation(string &s,int n)
{
	string ans;
	
	Rec(s,n,0,ans);
	
	cout<<endl;
}
signed main()
{
	string s = "ABC";
	int n = s.length();
	
	SpacePermutation(s,n);

	return 0;
}
