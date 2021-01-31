#include<bits/stdc++.h>
using namespace std;
void Rec(string &s,int n,int i,string &ans,vector<string> &a,int &inv,int o,int c)
{
    if(i == n)
    {
        if(ans.size() == n - inv)
        {
            if(!o && !c )
            {
            	bool flag = true;
            	for(auto j:a)
            	if(j == ans)
            	{
            		flag = false;
            		break;
				}
				if(flag)
				a.push_back(ans);
			}
        }
        return;
    }
    
    if(s[i] == '(' || s[i] == ')')
    Rec(s,n,i+1,ans,a,inv,o,c);
    
    if(s[i] == '(')
    o++;
    
    else if(s[i] == ')')
    {
    	if(o)  o--;
    	else  c++;
	}
    
    ans.push_back(s[i]);
    Rec(s,n,i+1,ans,a,inv,o,c);
    ans.pop_back();
}
vector<string> removeInvalidParentheses(string s)
{
    int n = s.length();
    
    int o = 0 , c = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '(')
        o++;
        
        else if(s[i] == ')')
        {
            if(o == 0)  c++;
            else  o--;
        }
    }
    
    vector<string> a;
    string ans;
    int inv = o+c;
    o = c = 0;
    Rec(s,n,0,ans,a,inv,o,c);
    
    return a;
}
signed main()
{
	string s = "()())()";
	
	vector<string> a = removeInvalidParentheses(s);
	
	for(auto i : a)
	cout<< i << endl;
	
	return 0;
}
